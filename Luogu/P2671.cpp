#include <bits/stdc++.h>
#define int long long

const int N = 1e5 + 5, MOD = 10007;

int lst[N][2], dp[N][2], preX[N][2], preNumX[N][2], preCnt[N][2], PreXNumX[N][2], n, m, num[N], c[N];

namespace RunCode {
    void solve () {
        std :: cin >> n >> m;
        for (int i = 1; i <= n; i ++) std :: cin >> num[i];
        for (int i = 1; i <= n; i ++) std :: cin >> c[i];
        for (int i = 1; i <= n; i ++) {
            int t = i & 1;
            preX[i][t] = preX[lst[c[i]][t]][t] + i;
            preX[i][t] %= MOD;
            preNumX[i][t] = preNumX[lst[c[i]][t]][t] + num[i];
            preNumX[i][t] %= MOD;
            preCnt[i][t] = preCnt[lst[c[i]][t]][t] + 1;
            preCnt[i][t] %= MOD;
            PreXNumX[i][t] = PreXNumX[lst[c[i]][t]][t] + i * num[i];
            PreXNumX[i][t] %= MOD;
            
            dp[i][t] += num[i] * preX[lst[c[i]][t]][t];
            dp[i][t] %= MOD;
            dp[i][t] += i * preNumX[lst[c[i]][t]][t];
            dp[i][t] %= MOD;
            dp[i][t] += i * num[i] * preCnt[lst[c[i]][t]][t];
            dp[i][t] %= MOD;
            dp[i][t] += PreXNumX[lst[c[i]][t]][t];
            dp[i][t] %= MOD;
            lst[c[i]][t] = i;
        }
        // std :: cout << dp[n][n & 1] + dp[n - 1][!(n & 1)];
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            ans += dp[i][i & 1];
            ans %= MOD;
            // ans += dp[lst[i][1]][1];
        }
        std :: cout << ans % MOD;
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/