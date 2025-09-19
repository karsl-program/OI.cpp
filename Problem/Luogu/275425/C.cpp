#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int n, sum = 0, idx = 0, x;
        std :: cin >> n;
        for (int i = 0; i < n; i ++) {
            std :: cin >> x;
            if (!x) sum += 100;
            else if (x == 1) sum += ((++ idx) & 1) * 50 - (!(idx & 1)) * 30;
            std :: cout << sum << '\n';
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