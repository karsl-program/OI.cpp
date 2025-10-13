#include <bits/stdc++.h>

constexpr int N = 35;

int dp[N][N], n, m;

namespace RunCode {
    void solve () {
        std :: cin >> n >> m;
        dp[0][1] = 1;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) dp[i][j] = dp[i - 1][(j == 1 ? n : j - 1)] + dp[i - 1][(j == n ? 1 : j + 1)];
        }
        std :: cout << dp[m][1];
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/