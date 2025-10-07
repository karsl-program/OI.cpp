#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        long long n, m, x, y;
        std :: cin >> n >> m >> x >> y;
        long long ans = x * m + y * n;
        std :: cout << n * m - ans + x * y;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/