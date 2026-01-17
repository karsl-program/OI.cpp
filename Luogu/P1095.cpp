#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int m, s, t;
        std :: cin >> m >> s >> t;
        std :: vector <int> dp (t + 1);
        for (int i = 1; i <= t; i ++) {
            if (m >= 10) {
                dp[i] = dp[i - 1] + 60;
                m -= 10;
            } else m += 4, dp[i] = dp[i - 1];
        }
        for (int i = 1; i <= t; i ++) {
            dp[i] = std :: max (dp[i], dp[i - 1] + 17);
            if (dp[i] > s) return (void)(std ::cout << "Yes\n" << i << "\n");
        }
        std :: cout << "No\n" << dp[t] << "\n";
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/