#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        std::string S;
        std::cin >> S;

        int L = S.length();
        int mid = (L + 1) / 2 - 1;
        std::string res = S.substr(0, mid) + S.substr(mid + 1);

        std::cout << res << std::endl;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/