import sys
import math

# Check if numpy is available, otherwise we might need a fallback or fail
try:
    import numpy as np
except ImportError:
    # In a real scenario, we might implement a pure python matrix lib, 
    # but for "Machine Learning" task, numpy is almost certainly expected.
    sys.stderr.write("Error: Numpy not found.\n")
    sys.exit(1)

# Increase recursion depth just in case
sys.setrecursionlimit(2000)

def log(msg):
    # Debug logging to stderr
    sys.stderr.write(str(msg) + "\n")

class Trader:
    def __init__(self):
        self.n = 0
        self.D = 0
        self.init_cash = 0.0
        self.current_cash = 0.0
        self.L = 100
        self.alpha = 0.0
        self.com_min = 5.0
        self.beta = 0.0
        self.K_max = 0
        
        self.codes = []
        self.code_to_idx = {}
        
        # Historical Data Storage
        # We will store data as numpy arrays for fast processing
        # Shape: (n_days, n_stocks, n_features)
        # Features: open, high, low, close, volume, amount
        self.history_price = [] # List of (n_stocks, 6) arrays
        self.dates = []
        
        # Portfolio State
        self.positions = np.zeros(0, dtype=int) # Will init after getting n
        
        # Model Weights (Simple Linear Model per stock or global?)
        # Global model is better for generalization
        self.weights = None
        self.train_X = []
        self.train_y = []
        
        # Hyperparameters
        self.lookback = 20 # Days to look back for features
        self.train_window = 60 # Days of history to keep for training
        self.top_k = 10 # Number of stocks to hold
        
    def parse_init(self):
        line = sys.stdin.readline()
        if not line: return False
        parts = line.strip().split()
        if parts[0] == 'INIT':
            self.n = int(parts[1])
            self.D = int(parts[2])
            self.init_cash = float(parts[3])
            self.current_cash = self.init_cash
            self.L = int(parts[4])
            self.alpha = float(parts[5])
            self.com_min = float(parts[6])
            self.beta = float(parts[7])
            self.K_max = int(parts[8])
            return True
        return False

    def parse_daily_data(self):
        # Read n lines
        daily_data = []
        codes = []
        
        # Data columns: 
        # 0:date, 1:code, 2:open, 3:high, 4:low, 5:close, 
        # 6:volume, 7:amount, 8:amplitude, 9:pct_chg, 10:change, 11:turnover
        
        # We process line by line
        # We need to map code to index efficiently
        
        # Pre-allocate array for this day: n x 6 (O, H, L, C, V, Amt)
        day_matrix = np.zeros((self.n, 6), dtype=np.float32)
        
        for i in range(self.n):
            line = sys.stdin.readline()
            parts = line.strip().replace(',', ' ').split() # Handle csv or space
            
            if i == 0:
                self.dates.append(parts[0])
                
            code = parts[1]
            if self.day == 0:
                self.codes.append(code)
                self.code_to_idx[code] = i
            
            # Parse floats
            # indices: 2,3,4,5,6,7
            vals = [float(x) for x in parts[2:8]]
            day_matrix[i] = vals
            
        if self.day == 0:
            self.positions = np.zeros(self.n, dtype=int)
            
        self.history_price.append(day_matrix)
        
    def extract_features(self, day_idx):
        # Extract features for all stocks at a given day_idx (using history up to day_idx)
        # We need at least 'lookback' days (indices day_idx-lookback+1 to day_idx)
        # So day_idx must be >= lookback - 1
        if day_idx < self.lookback - 1:
            return None
            
        # Get slice of history: (lookback, n_stocks, 6)
        # indices: day_idx - lookback + 1 to day_idx + 1 (exclusive)
        start_idx = day_idx - self.lookback + 1
        end_idx = day_idx + 1
        
        recent_frames = self.history_price[start_idx : end_idx]
        data = np.stack(recent_frames, axis=1) # (n, lookback, 6)
        
        closes = data[:, :, 3]
        opens = data[:, :, 0]
        highs = data[:, :, 1]
        lows = data[:, :, 2]
        volumes = data[:, :, 4]
        
        current_close = closes[:, -1]
        
        # 1. Momentum / Returns
        ret_1d = closes[:, -1] / closes[:, -2] - 1.0
        ret_5d = closes[:, -1] / closes[:, -5] - 1.0
        ret_10d = closes[:, -1] / closes[:, -10] - 1.0
        ret_20d = closes[:, -1] / closes[:, -20] - 1.0 if self.lookback >= 20 else np.zeros(self.n)
        
        # 2. Volatility (std of last 10 days returns)
        # daily returns for last 10 days
        daily_rets = closes[:, 1:] / closes[:, :-1] - 1.0
        vol_10d = np.std(daily_rets[:, -10:], axis=1)
        
        # 3. MA Trend
        ma_5 = np.mean(closes[:, -5:], axis=1)
        ma_10 = np.mean(closes[:, -10:], axis=1)
        ma_20 = np.mean(closes[:, -20:], axis=1) if self.lookback >= 20 else ma_10
        
        dist_ma5 = current_close / ma_5 - 1.0
        dist_ma10 = current_close / ma_10 - 1.0
        dist_ma20 = current_close / ma_20 - 1.0
        
        # 4. RSI (14 days) - Simplified
        # We need at least 15 days of data for 14-day RSI
        rsi = np.zeros(self.n)
        if self.lookback >= 15:
            delta = daily_rets[:, -14:]
            up = np.maximum(delta, 0)
            down = -np.minimum(delta, 0)
            avg_gain = np.mean(up, axis=1)
            avg_loss = np.mean(down, axis=1)
            
            rs = avg_gain / (avg_loss + 1e-9)
            rsi = 100.0 - (100.0 / (1.0 + rs))
            rsi = rsi / 100.0 # Normalize to 0-1
            
        # 5. Volume change
        vol_ma5 = np.mean(volumes[:, -5:], axis=1)
        vol_ratio = volumes[:, -1] / (vol_ma5 + 1e-5)
        
        # Stack features
        features = np.column_stack([
            ret_1d, ret_5d, ret_10d, 
            vol_10d, 
            dist_ma5, dist_ma10, dist_ma20,
            rsi,
            vol_ratio
        ])
        
        # Handle NaNs
        features = np.nan_to_num(features)
        
        # Normalize features (Robust scaling)
        # Subtract median, divide by IQR (or std)
        # We do this per feature across all stocks
        median = np.median(features, axis=0)
        q75, q25 = np.percentile(features, [75 ,25], axis=0)
        iqr = q75 - q25
        iqr[iqr == 0] = 1.0
        
        features = (features - median) / iqr
        
        # Clip outliers
        features = np.clip(features, -3.0, 3.0)
        
        return features

    def train_and_predict(self):
        # We need to construct a training set from history
        # X: Features at day d
        # y: Return at day d+1
        
        # Condition: We need day-2 >= lookback - 1
        if self.day >= self.lookback + 1:
            # Training Sample
            prev_feat_idx = self.day - 2
            prev_features = self.extract_features(prev_feat_idx)
            
            if prev_features is not None:
                # Calculate actual return for day-1
                current_closes = self.history_price[-1][:, 3] # Day d-1
                prev_closes = self.history_price[-2][:, 3]    # Day d-2
                
                # Avoid division by zero
                valid_mask = prev_closes > 1e-4
                actual_returns = np.zeros_like(current_closes)
                actual_returns[valid_mask] = current_closes[valid_mask] / prev_closes[valid_mask] - 1.0
                
                # Normalize Targets (Rank Transformation)
                ranks = np.argsort(np.argsort(actual_returns))
                target = ranks / (len(ranks) - 1.0) # 0.0 to 1.0
                target = target - 0.5 
                
                # Let's keep a sliding window of training data to adapt
                if len(self.train_X) > self.train_window:
                    # Remove old data
                    self.train_X.pop(0)
                    self.train_y.pop(0)
                
                self.train_X.append(prev_features)
                self.train_y.append(target)
            
        # Need enough data to train (at least 2 days of data)
        if len(self.train_X) < 2:
            # Not enough data, return random or zeros
            return np.zeros(self.n)
            
        # Flatten data for training
        X_train = np.vstack(self.train_X) # (N_samples, n_feats)
        y_train = np.concatenate(self.train_y) # (N_samples,)
        
        # Train Ridge Regression
        # w = (X^T X + alpha I)^-1 X^T y
        # Add bias term
        X_train = np.column_stack([X_train, np.ones(X_train.shape[0])])
        
        reg_alpha = 50.0 # Increased regularization for stability
        n_feats = X_train.shape[1]
        
        # Normal Equation with Ridge
        A = X_train.T @ X_train + reg_alpha * np.eye(n_feats)
        b = X_train.T @ y_train
        try:
            w = np.linalg.solve(A, b)
        except np.linalg.LinAlgError:
            w = np.zeros(n_feats)
            
        # Predict for tomorrow
        # Features based on today (self.day - 1)
        curr_feat_idx = self.day - 1
        current_features = self.extract_features(curr_feat_idx)
        
        if current_features is None:
             return np.zeros(self.n)
             
        # Add bias
        current_features_b = np.column_stack([current_features, np.ones(self.n)])
        
        predictions = current_features_b @ w
        return predictions


    def run(self):
        if not self.parse_init():
            return
            
        # Parse Day 0
        self.parse_daily_data()
        # Day 0 output (Usually nothing or initial positioning)
        # We can't calculate features yet (need lookback)
        # Just output DONE
        print("DONE")
        sys.stdout.flush()
        self.day += 1
        
        while self.day <= self.D:
            # 1. Receive data for Day t (wait, flow is: Out orders -> Recv Day t)
            # The loop structure in prompt:
            # Init (Recv Day 0)
            # Loop t = 1 to D:
            #   Based on t-1, output orders
            #   Recv Day t
            
            # So when we enter loop t=1:
            # We have Day 0 data. We output orders for Day 1 Open.
            # Then we Recv Day 1 data.
            
            # My logic inside loop:
            # Predict based on history (up to self.day-1)
            # Output orders
            # Recv data for self.day
            
            # Prediction
            scores = np.zeros(self.n)
            if self.day > self.lookback:
                scores = self.train_and_predict()
                
            # Generate Orders
            self.generate_orders(scores)
            
            print("DONE")
            sys.stdout.flush()
            
            # Recv Data
            if self.day < self.D: # Last day we still recv data but loop ends?
                # Prompt: "Loop t=1 to D... Judge sends t data... Loop continues"
                # "Last day special handling: Recv Day D data, program can submit orders (exec at close)"
                # My loop is `while self.day <= self.D`
                # Let's align with prompt steps carefully.
                pass
            
            # Read next day data
            # If self.day == D, we read Day D data.
            # Then we go to top of loop? No.
            # Prompt:
            # 2. Daily Loop (t=1 to D):
            #    Output orders (based on t-1).
            #    Output DONE.
            #    Judge executes at t Open.
            #    Judge sends t data.
            # 3. Last Day: Recv Day D data... Program submit orders... Exec at Close.
            
            # So after we print DONE for t=D, we receive Day D data.
            # Then we have one more chance to submit orders (for Close).
            
            self.parse_daily_data()
            
            if self.day == self.D:
                # This is the "Last Day Special Handling"
                # We just received Day D data.
                # We can submit orders to be executed at Day D Close.
                # Usually we sell everything to maximize cash?
                # "Final score = Total Assets". So Cash == Stock in value roughly.
                # But selling incurs tax/fee. 
                # If we maximize "Total Assets", holding stock is fine.
                # Unless stock is expected to crash at Close? Unlikely.
                # Selling incurs transaction cost. Better to HOLD if we just want max assets.
                # Wait, "Final score = Cash + Market Value".
                # Selling reduces asset by fee. So DO NOT SELL unless alpha is negative (impossible).
                # So for the last extra step, we usually do nothing or balance if needed.
                # We can just output DONE.
                print("DONE")
                sys.stdout.flush()
                break
                
            self.day += 1
            
        # Finish
        # Judge will print FINISH. We don't need to read it.

    def generate_orders(self, scores):
        # Update State Logic:
        # 1. We have `pending_orders` from yesterday (t-1).
        # 2. They executed at t-1 Open.
        # 3. We have t-1 Open prices now (in history_price[-1]).
        # 4. Update cash and positions.
        
        if hasattr(self, 'pending_orders') and self.pending_orders:
            # These were submitted at t-1 (based on t-2 data)
            # Executed at t-1 Open.
            # We have t-1 data in self.history_price[-1]
            day_t_minus_1_data = self.history_price[-1] 
            
            opens = day_t_minus_1_data[:, 0]
            
            for code, qty, side in self.pending_orders:
                if code not in self.code_to_idx: continue
                idx = self.code_to_idx[code]
                price = opens[idx]
                
                if price <= 1e-4: # Stoppage or error
                    continue
                    
                cost = price * qty
                
                if side == 'BUY':
                    commission = max(self.com_min, cost * self.alpha)
                    total_cost = cost + commission
                    
                    if self.current_cash >= total_cost:
                        self.current_cash -= total_cost
                        self.positions[idx] += qty
                
                elif side == 'SELL':
                    # We assume sell always succeeds if we had position
                    # But we need to verify if we actually had it?
                    # The logic below ensures we only sell what we have.
                    if self.positions[idx] >= qty:
                        tax = cost * self.beta
                        commission = max(self.com_min, cost * self.alpha)
                        revenue = cost - tax - commission
                        
                        self.current_cash += revenue
                        self.positions[idx] -= qty
            
            self.pending_orders = []

        # Strategy: Buy top K stocks with positive score
        # Sell stocks not in top K or with negative score
        
        # Add Turnover Buffer
        # If we already hold stock, increase its score slightly to discourage selling
        # unless there is a much better opportunity.
        
        adjusted_scores = scores.copy()
        current_holdings_mask = self.positions > 0
        adjusted_scores[current_holdings_mask] += 0.05 # Add buffer
        
        # Sort indices by score descending
        ranked_indices = np.argsort(adjusted_scores)[::-1]
        
        target_indices = []
        for idx in ranked_indices:
            if len(target_indices) >= self.top_k:
                break
            target_indices.append(idx)
        
        target_set = set(target_indices)
        
        new_orders = [] 
        
        # Use temporary state for planning
        sim_positions = self.positions.copy()
        sim_cash = self.current_cash
        
        # 1. Sell non-targets
        for idx in range(self.n):
            if sim_positions[idx] > 0 and idx not in target_set:
                qty = sim_positions[idx]
                code = self.codes[idx]
                new_orders.append((code, qty, 'SELL'))
                print(f"SELL {code} {qty}")
                
                # Estimate cash update for buying power
                est_price = self.history_price[-1][idx, 3] # Close
                est_val = est_price * qty
                est_tax = est_val * self.beta
                est_comm = max(self.com_min, est_val * self.alpha)
                
                sim_cash += (est_val - est_tax - est_comm)
                sim_positions[idx] = 0 

        # 2. Buy targets
        if not target_indices:
            self.pending_orders = new_orders
            return
            
        num_targets = len(target_indices)
        
        # Estimate Total Assets to determine position sizing
        # Assets = Cash + Stock Value
        # We use sim_cash (which includes proceeds from sells)
        total_asset_val = sim_cash
        for idx in range(self.n):
            if sim_positions[idx] > 0: # Holding a target
                price = self.history_price[-1][idx, 3]
                total_asset_val += sim_positions[idx] * price
                
        target_val_per_stock = total_asset_val / num_targets * 0.98 # Safety margin
        
        for idx in target_indices:
            est_price = self.history_price[-1][idx, 3]
            if est_price < 1e-4: continue
            
            current_qty = sim_positions[idx]
            current_val = current_qty * est_price
            
            shortfall = target_val_per_stock - current_val
            
            # If we need to buy more
            if shortfall > est_price * 100: 
                qty_to_buy = int(shortfall / est_price / 100) * 100
                if qty_to_buy > 0:
                    cost = qty_to_buy * est_price
                    comm = max(self.com_min, cost * self.alpha)
                    if sim_cash > cost + comm:
                        code = self.codes[idx]
                        new_orders.append((code, qty_to_buy, 'BUY'))
                        print(f"BUY {code} {qty_to_buy}")
                        
                        sim_cash -= (cost + comm)
                        sim_positions[idx] += qty_to_buy
        
        self.pending_orders = new_orders


if __name__ == "__main__":
    t = Trader()
    t.run()
