#include <bits/stdc++.h>
#define int long long
constexpr int N = 2e5 + 5;
int fr[N];

namespace RunCode {
    void solve () {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            std::cin >> a;
            fr[a]++;
        }

        int t = 0;
        int s1 = 0;
        int sfb = 0;

        for (int v = 1; v <= n; v++) {
            int f = fr[v];
            if (f >= 2) {
                int c2 = f * (f - 1) / 2;
                t += c2;
                s1 += c2 * (n - f);
                sfb += f * c2;
            }
        }

        int s2 = t * n - sfb;
        int an = s1 + s2;

        std::cout << an / 2 << std::endl;
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/