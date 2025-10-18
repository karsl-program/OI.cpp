#include <bits/stdc++.h>
const int N = 1e5 + 5;
int p[N];
namespace RunCode {
    void solve () {
        int n, x;
        std :: cin >> n >> x;
        for (int i = 1; i <= n; i ++) {
            std :: cin >> p[i];
        }
        // sort (p + 1, p + n + 1);
        int s = std :: abs (p[1] - x);
        for (int i = 2; i <= n; i ++) {
            s = std :: __gcd (s, std :: abs (p[i] - x));
        }
        std :: cout << s;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/