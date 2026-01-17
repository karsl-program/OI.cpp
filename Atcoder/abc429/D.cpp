#include <bits/stdc++.h>

#define int long long

namespace RunCode {
    void solve() {
        int n, m, c;
        std::cin >> n >> m >> c;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        auto b = a;
        std::sort(b.begin(), b.end());

        int thr = n - c + 1;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x = a[i];
            int f = std::lower_bound(b.begin(), b.end(), x) - b.begin();
            int c1 = 0;

            if (f + thr - 1 < n) {
                int v = b[f + thr - 1];
                int l = std::max(x, v);
                if (l < m) c1 = m - l;
            }

            int bs = n - f;
            int t2 = thr - bs;
            int c2 = 0;

            if (t2 <= 0) {
                c2 = x;
            } else {
                if (t2 - 1 < n) {
                    int w = b[t2 - 1];
                    if (w <= x - 1) c2 = x - w;
                }
            }

            ans += c1 + c2;
        }

        std::cout << ans << '\n';
    }
}

signed main() {
    RunCode :: solve();
    
    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/