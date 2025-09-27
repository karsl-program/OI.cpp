#include <bits/stdc++.h>

constexpr int N = 5 * 1e4 + 5;

int dp_max[N][20], dp_min[N][20], lg[N], h[N], l, r;

namespace RunCode {
    void solve () {
        std :: ios :: sync_with_stdio (false);
        std :: cin.tie (0), std :: cout.tie (0);
        int n, q;
        std :: cin >> n >> q;
        lg[0] = -1;
        for (int i = 1; i <= n; i ++) lg[i] = lg[i >> 1] + 1;
        for (int i = 1; i <= n; i ++) std :: cin >> h[i], dp_max[i][0] = dp_min[i][0] = h[i];
        for (int i = 1; i < 20; i ++) {
            for (int s = 1; s + (1 << i) <= n + 1; s ++) {
                dp_max[s][i] = std :: max (dp_max[s][i - 1], dp_max[s + (1 << (i - 1))][i - 1]);
                dp_min[s][i] = std :: min (dp_min[s][i - 1], dp_min[s + (1 << (i - 1))][i - 1]);
            }
        }
        while (q --) {
            std :: cin >> l >> r;
            int _1 = std :: max (dp_max[l][lg[r - l + 1]], dp_max[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]);
            int _2 = std :: min (dp_min[l][lg[r - l + 1]], dp_min[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]);
            std :: cout << _1 - _2 << "\n";
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