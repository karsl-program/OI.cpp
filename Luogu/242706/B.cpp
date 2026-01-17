#include <bits/stdc++.h>
#define int long long
const int N = 500005;

int n, m;
int B[N];
int f[N];
namespace RunCode {
    void solve () {
        std::cin >> n >> m;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            int a, b, c;
            std::cin >> a >> b >> c;
            B[a] += b;
            if (c) f[a]++, tot++;
        }

        int min_B = 1e18;
        for (int j = 1; j <= m; j++) {
            if (B[j] < min_B) {
                min_B = B[j];
            }
        }

        int r = std::min(tot, min_B);
        int l = 0, ans = 0;

        while (l <= r) {
            int k = (l + r) / 2;
            bool ok = true;
            int _tot = 0;

            for (int j = 1; j <= m; j++) {
                if (k > B[j]) {
                    ok = false;
                    break;
                }
                int maxx = B[j] - k;
                _tot += std::min(f[j], maxx);
            }

            if (!ok || _tot < k) {
                r = k - 1;
            } else {
                ans = k;
                l = k + 1;
            }
        }

        std::cout << ans << std::endl;
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/