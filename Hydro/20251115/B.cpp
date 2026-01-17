#include <bits/stdc++.h>
#define int __int128
constexpr int MOD = 1e9 + 7, N = 105;

int f[N];

void print (int x) {
    if (x > 9) print (x / 10);
    putchar (x % 10 + '0');
}

int read () {
    int x = 0, f = 1; char ch = getchar ();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar (); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar (); }
    return x * f;
}

namespace RunCode {
    void solve () {
        int n, sum = 0;
        n = read();
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] * i % MOD, sum = (sum + f[i]) % MOD;
        }
        print ((sum - f[n] + MOD) % MOD);
    }
}

signed main () {
    freopen ("depth.in", "r", stdin);
    freopen ("depth.out", "w", stdout);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/