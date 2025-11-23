#include <bits/stdc++.h>

constexpr int N = 1e5 + 5, C = 20;

int C, n, dp[1 << C], pre[N], val[1 << C], card[C], ans, x;

namespace RunCode {
    void solve () {
        std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
        std :: cin >> C >> n;
        for (int i = 1; i <= C; i ++) std :: cin >> card[i];
        for (int i = 1; i <= n; i ++) std :: cin >> x, pre[i] = pre[i - 1] + x;
        
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/