#include <bits/stdc++.h>

const int N = 505;

int n, a[N][N], dp[N][N];

namespace RunCode {
    void solve () {
        std :: cin >> n;
        for (int i = 1; i <= n; i ++) {
            int flag = 0;
            for (int j = 1; j <= n; j ++) {
                std :: cin >> a[i][j];
                if (i == a[i][j]) {
                    flag = 1;
                    continue;
                }
                if (flag) continue;
                dp[i][a[i][j]] = 1;
            }
        }
        for (int k = 1; k <= n; k ++) {
            for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= n; j ++) {
                    dp[i][j] |= dp[i][k] & dp[k][j];
                }
            }
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (dp[i][a[i][j]] & dp[a[i][j]][i]) {
                    std :: cout << a[i][j] << '\n';
                    goto end;
                }
            }
            std :: cout << i << '\n';
            end: continue;
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