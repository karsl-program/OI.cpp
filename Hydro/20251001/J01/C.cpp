#include <bits/stdc++.h>
#define int long long

namespace RunCode {
    void solve () {
        int n, m;
        std :: cin >> n >> m;
        
        std :: vector <int> a(n);
        std :: map <int, int> gm;

        for (int i = 0; i < n; i++) {
            std :: cin >> a[i];
            gm[a[i]] ++;
        }
        
        std :: vector<int> g;
        for (auto& p : gm) g.push_back(p.second);

        std :: sort (g.begin (), g.end ());
        
        int k = g.size();
        std :: vector<int> pre (k + 1, 0);
        for (int i = 0; i < k; i++) {
            pre[i + 1] = pre[i] + g[i];
        }
        
        int ma_k = 0;
        
        for (int i = 0; i < k; i ++) {
            int min_f = g[i];
            int max_f = min_f + m;
            
            int j = std :: upper_bound (g.begin (), g.end (), max_f) - g.begin ();
            
            int _k = pre[j] - pre[i];
            if (j < k) _k += (k - j) * max_f;
            
            ma_k = std :: max (ma_k, _k);
        }
        
        std :: cout << n - ma_k;
    }
}

signed main () {
    freopen ("put.in", "r", stdin);
    freopen ("put.out", "w", stdout);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/