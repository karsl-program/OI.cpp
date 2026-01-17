#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int n, cnt = 0;
        std :: cin >> n;
        for (int i = 0 ;i < n; i ++) {
            int x;
            std :: cin >> x;
            if (x == 1) cnt ++;
        }
        std :: cout << cnt << "\n";
    }
}

int main () {
    freopen ("align.in", "r", stdin);
    freopen ("align.out", "w", stdout);
    int t; std :: cin >> t; while (t --)
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/