#include <bits/stdc++.h>
const int N = 2 * 1e5 + 5;
#define int long long
int a[N];
namespace RunCode {
    void solve () {
        std :: ios :: sync_with_stdio (false);
        std :: cin.tie (0), std :: cout.tie (0);
        int n, q, u = 0;
        std :: cin >> n >> q;
        for (int i = 1; i <= n; i ++) std :: cin >> a[i];
        // for (int i = n + 1; i <= 3 * n; i ++) a[i] = a[(i - 1) % n + 1];
        for (int i = 1; i <= n; i ++) a[i] += a[i - 1];
        while (q --) {
            int op, l, r;
            std :: cin >> op;
            if (op == 1) {
                std :: cin >> l;
                u += l, u %= n;
            } else {
                std :: cin >> l >> r;
                l += u; l = (l - 1) % n + 1;
                r += u; r = (r - 1) % n + 1;
                if (r < l) std :: cout << a[n] - a[l - 1] + a[r];
                else std :: cout << a[r] - a[l - 1];
                std :: cout << '\n';
            }
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