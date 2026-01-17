#include <bits/stdc++.h>

int n, k, ans;

namespace RunCode {
    void solve () {
        std :: cin >> n >> k;
        while (true) {
            if (__builtin_popcount(n) <= k) break;
            ans += n & (-n);
            n += n & (-n);
        }
        std :: cout << ans;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/