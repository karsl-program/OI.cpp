#include <bits/stdc++.h>

constexpr int N = 1005;

int d[N][N];

namespace RunCode {
    void solve () {
        int n, m;
        std :: cin >> n >> m;
        while (m --) {
            int x1, y1, x2, y2;
            std :: cin >> x1 >> y1 >> x2 >> y2;
            d[x1][y1] ++;
            d[x2 + 1][y1] --;
            d[x1][y2 + 1] --;
            d[x2 + 1][y2 + 1] ++;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
                std :: cout << d[i][j] << " ";
            }
            std :: cout << "\n";
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