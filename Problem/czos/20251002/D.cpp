#include <bits/stdc++.h>

const int N = 305;
int dp[N][N], n, a[N];

namespace RunCode {
    void solve () {
        std :: cin >> n;
        for (int i = 1; i <= n; i ++) std :: cin >> a[i];
        a[0] = a[n + 1] = 1;
        for (int len = 2; len <= n + 1; len ++) {
            for (int i = 0; i + len <= n + 1; i ++) {
                int j = i + len;
                for (int k = i + 1; k < j; k ++) dp[i][j] = std :: max (dp[i][j], dp[i][k] + dp[k][j] + a[k] * a[i] * a[j]);
            }
        }
        std :: cout << dp[0][n + 1];
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/