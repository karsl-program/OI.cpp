#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int a, b, c, k;
        std :: cin >> a >> b >> c;
        std :: cin >> k;
        if (k == 2) std :: cout << "Fail to pay.";
        else std :: cout << a + b + c;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/