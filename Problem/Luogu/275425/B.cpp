#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int a; std :: cin >> a >> a;
        std :: cout << (5 - a % 5 + 3) % 5;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/