#include <bits/stdc++.h>

int a[305][305];

namespace RunCode {
    void solve () {
        int n, m, x, c;
        std :: cin >> n >> m >> x;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                std :: cin >> a[i][j];
            }
        }
        std :: cin >> c;
        bool f = false;
        for (int j = 1; j <= m; j ++) {
            int minn = 1e9;
            for (int i = 1; i <= n; i ++) {
                minn = std :: min (minn, a[i][j]);
            }
            int maxx = 0;
            for (int i = 1; i <= n; i ++) {
                maxx = std :: max (maxx, a[i][j]);
            }
            if (maxx - minn < 2) {f = true; break;}
            c -= !(a[x][j] > minn && a[x][j] < maxx);
            if (c < 0) {f = true; break;}
        }
        std :: cout << (f ? "up" : "down") << '\n';
    }
}

int main () {
    int t; std :: cin >> t; while (t --)
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/