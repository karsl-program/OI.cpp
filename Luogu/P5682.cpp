#include <bits/stdc++.h>

constexpr int N = 2e5 + 5;
int a[N], n;

namespace RunCode {
    void solve () {
        std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
        std :: cin >> n;
        for (int i = 1; i <= n; i ++) std :: cin >> a[i];
        std :: sort (a + 1, a + n + 1);
        int cnt = std :: unique (a + 1, a + n + 1) - a - 1;
        if (cnt < 3) return std :: cout << -1, void ();
        std :: cout << std :: max (a[cnt - 2], a[cnt] % a[cnt - 1]);
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/