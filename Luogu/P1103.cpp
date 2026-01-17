#include <bits/stdc++.h>
#define fi first
#define se second
#define pii std :: pair <int, int>
constexpr int N = 105;
int n, k, dp[N][N];
pii a[N];

namespace RunCode {
    void solve () {
        std :: cin >> n >> k;
        memset (dp, 0x3f, sizeof (dp));
        for (int i = 1; i <= n; i ++) std :: cin >> a[i].fi >> a[i].se, dp[i][1] = 0;
        std :: sort (a + 1, a + n + 1);
        for (int i = 2; i <= n; i ++) {
            for (int j = 1; j < i; j ++) {
                for (int l = 2; l <= std :: min (i, n - k); l ++) {
                    dp[i][l] = std :: min (dp[i][l], dp[j][l - 1] + abs (a[i].se - a[j].se));
                }
            }
        }
        int res = 2147483647;
        for (int i = 1; i <= n; i ++) res = std :: min (res, dp[i][n - k]);
        std :: cout << res << '\n';
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/