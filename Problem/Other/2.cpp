#include <bits/stdc++.h>

constexpr int N = 1e5 + 5, MOD = 1e9 + 7;
int dp[N], pre[N], t, k;

namespace RunCode {
    void solve () {
        std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
        std :: cin >> t >> k;
        dp[0] = pre[0] = 1;
        for (int i = 1; i < k; i ++) {
            dp[i] = 1;
            pre[i] = pre[i - 1] + 1;
        }
        for (int i = k; i < N; i ++) dp[i] = (dp[i - 1] + dp[i - k]) % MOD, pre[i] = (pre[i - 1] + dp[i]) % MOD;
        while (t --) {
            int l, r; std :: cin >> l >> r;
            std :: cout << (pre[r] - pre[l - 1] + MOD) % MOD << '\n';
        }
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/