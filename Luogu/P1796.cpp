#include <bits/stdc++.h>
#define int long long

namespace RunCode {
    void solve () {
        int N;
        std::cin >> N;

        std::vector<std::vector<int>> dp(N + 1);
        dp[0].resize(1, 0);

        for (int i = 1; i <= N; i++) {
            int K;
            std::cin >> K;
            dp[i].resize(K + 1, INT_MAX);

            for (int j = 1; j <= K; j++) {
                int p, c;
                while (std::cin >> p && p != 0) {
                    std::cin >> c;
                    if (dp[i-1][p] != INT_MAX) {
                        dp[i][j] = std::min(dp[i][j], dp[i-1][p] + c);
                    }
                }
            }
        }

        int res = INT_MAX;
        for (int j = 1; j < (int)dp[N].size(); j++) {
            res = std::min(res, dp[N][j]);
        }

        std::cout << (res == INT_MAX ? -1 : res) << std::endl;
    }
}

signed main () {
    RunCode :: solve ();
    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/