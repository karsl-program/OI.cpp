#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        std :: string s;
        std :: cin >> s;
        int a = 0, c = 0;
        for (char ch : s) {
            if (ch == 'A') a ++;
            else if (ch =='C') c += a;
        }
        std :: cout << (c == 0 ? "No" : (c > 1 ? "YesYesYes!" : "Yes")) << '\n';
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/