#include <bits/stdc++.h>

#define int unsigned long long

int n, m, c, k, lim, g, ans;

int rd () { int x; scanf ("%llu", &x); return x; }

namespace RunCode {
    void solve () {
        std :: cin >> n >> m >> c >> k;
        for (int i = 1; i <= n; i ++) g |= rd ();
        for (int i = 1; i <= m; i ++) lim |= (1ull << rd ()), rd ();
        for (int i = 0; i < k; i ++) {
            ans += ((g >> i) & 1) || (!((lim >> i) & 1));
        }
        // std :: cout << (unsigned long long)(-1) << std :: endl;
        if (ans == 64 && !n) return puts ("18446744073709551616"), void ();
        std :: cout << (unsigned long long)(ans == 64 ? -n : (1ull << ans) - n);
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/