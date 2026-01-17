#include <bits/stdc++.h>
#define int long long

namespace RunCode {
    void solve () {
        int T;
        scanf("%lld", &T);
        
        while (T --) {
            int x, y;
            scanf("%lld %lld", &x, &y);
            int d = y - x;
            int ans;
            if (d == 0) {
                ans = 0;
            } else if (d > 0) {
                if (d % 2 == 1) {
                    ans = 1;
                } else {
                    if (d % 4 == 2) {
                        ans = 2;
                    } else {
                        ans = 3;
                    }
                }
            } else {
                if (d % 2 == 0) {
                    ans = 1;
                } else {
                    ans = 2;
                }
            }

            printf ("%lld\n", ans);
        }
    }
}

signed main () {
    freopen("red.in", "r", stdin);
    freopen("red.out", "w", stdout);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/