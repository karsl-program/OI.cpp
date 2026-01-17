#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int S, A, B, X;
        std::cin >> S >> A >> B >> X;
        int T = A + B;
        int q = X / T;
        int r = X % T;
        int ans = q * S * A + S * std::min(r, A);
        std::cout << ans << '\n';
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/