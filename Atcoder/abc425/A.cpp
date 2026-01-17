#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int n, sum = 0;
        std :: cin >> n;
        for (int i = 1, p = -1; i <= n; i ++, p *= -1) {
            sum += p * i * i * i;
        }
        std :: cout << sum;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/