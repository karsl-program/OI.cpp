#include <bits/stdc++.h>
#define int long long

/*
x = k * k - c * 10^l - c
max(1,10^(l-1)−C) <= x <= min(D,10^(l-1)−C)
k * k = c * 10^l + c + x x[1,d]
C*10^l + max(1,10^(l-1)) <= k*k <= C*10^l + min(D+C,10^(l-1))
*/

namespace RunCode {
    int len (int x) {
        int r = 0;
        while (x > 0) {
            r++;
            x /= 10;
        }
        return r;
    }

    void solve () {
        int T;
        std::cin >> T;
        while (T--) {
            int c, d;
            std :: cin >> c >> d;
            int ans = 0;
            int le = len(c + 1), r = len(c + d);
            
            for (int l = le; l <= r; l++) {
                int pow10 = 1;
                for (int i = 0; i < l; i++) pow10 *= 10;
                int minn = std :: max(1ll, pow10 / 10 - c), maxx = std :: min(d, pow10 - 1 - c);
                if (minn > maxx) continue;
                int mink2 = c*pow10+c+minn, maxk2 = c*pow10+c+maxx;
                int kmin = std :: sqrt(mink2), kmax = std :: sqrt(maxk2);
                if (kmin * kmin < mink2) kmin++;
                if (kmax * kmax > maxk2) kmax--;
                
                if (kmin <= kmax) ans += (kmax - kmin + 1);
            }
            std::cout << ans << "\n";
        }
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/