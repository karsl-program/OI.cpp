#include <bits/stdc++.h>
#define int long long
const int N = 1e6 + 5, MOD = 1e9 + 7;
int tot, ans[N], a[N];
inline int read () {
    int x = 0, f = 1;
    char ch = getchar ();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar ();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        // x > MOD ? x -= MOD : 0;
        x %= MOD;
        ch = getchar ();
    }
    return x * f;
}
int n, m;

bool check (int mod, int x) {
    int res = 0;
    for (int i = n; i; i --) {
        res = (a[i] + res) * x;
        while(res>=MOD)res -= MOD;
    }
    res = a[0] + res;

    return res == 0;
}

namespace RunCode {
    void solve () {
        scanf ("%lld%lld", &n, &m);
        for (int i = 0; i <= n; i++) a[i] = read ();
        for (int i = 1; i <= m; i ++) {
            if (check (MOD, i)) ans[++tot] = i;
        }
        printf ("%lld\n", tot);
        for (int i = 1; i <= tot; i++) printf ("%lld\n", ans[i]);
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/