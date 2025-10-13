#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace RunCode {
    void solve() {
        freopen ("takeout.in", "r", stdin);
        freopen ("takeout.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> s(k);
        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }
        
        vector<int> o(m);
        for (int i = 0; i < m; i++) {
            cin >> o[i];
        }
        
        sort(s.begin(), s.end());
        
        int td = 0;
        int cp = 1;
        
        for (int i = 0; i < m; i++) {
            int t = o[i];
            
            int dd = abs(cp - t);
            
            auto it = lower_bound(s.begin(), s.end(), cp);
            int sd = (int)1e18;
            
            if (it != s.end()) {
                sd = min(sd, abs(cp - *it));
            }
            if (it != s.begin()) {
                --it;
                sd = min(sd, abs(cp - *it));
            }
            
            td += min(dd, sd);
            
            cp = t;
        }
        
        cout << td << '\n';
    }
}

signed main() {
    RunCode :: solve();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/