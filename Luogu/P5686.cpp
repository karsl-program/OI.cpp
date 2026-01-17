#include <bits/stdc++.h>

#define int long long

const int N = 5e5 + 5, MOD = 1e9 + 7;

int preA[N], preB[N], ans, n, a[N], b[N];
int ppreA[N], ppreB[N], c[N], preC[N];

namespace RunCode {
    void solve () {
        std :: cin >> n;
        for (int i = 1; i <= n; i ++) std :: cin >> a[i], preA[i] = (preA[i - 1] + a[i]) % MOD;
        for (int i = 1; i <= n; i ++) std :: cin >> b[i], preB[i] = (preB[i - 1] + b[i]) % MOD;
        for (int i = 1; i <= n; i ++) {
            ppreA[i] = ppreA[i - 1] + preA[i], ppreA[i] %= MOD;
            ppreB[i] = ppreB[i - 1] + preB[i], ppreB[i] %= MOD;
            c[i] = preA[i] * preB[i] % MOD;
            preC[i] = (preC[i - 1] + c[i]) % MOD;
        }
        for (int i = 1; i <= n; i ++) {
            ans += c[i] * i % MOD + preC[i - 1] - preA[i] * ppreB[i - 1] % MOD - preB[i] * ppreA[i - 1] % MOD;
            ans %= MOD;
        }
        std :: cout << (ans + MOD) % MOD << std :: endl;
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/