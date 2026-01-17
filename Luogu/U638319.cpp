#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int n; std :: cin >> n;
        if (n & 1) std :: cout << "ODD\n";
        else std :: cout << "EVEN\n";
    }
}

int main () {
    int T; std :: cin >> T;
    while (T --) RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/