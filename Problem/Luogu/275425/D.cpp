#include <bits/stdc++.h>

const int N = 1e5 + 5;

int a[N];

namespace RunCode {
    void solve () {
        int n, m;
        std :: cin >> n >> m;
        for (int i = 0; i < n; i ++) {
            std :: cin >> a[0];
            a[a[0]] = a[a[0] + 1] = 1;
        }
        int flag = 0;
        for (int i = 1; i <= m; i ++) {
            if (a[i] == 0) flag ++;
        }
        if (!flag) std :: cout << "Accepted";
        else {
            std :: cout << flag << "\n";
            
            for (int i = 1; i <= m; i ++) {
                if (a[i] == 0) std :: cout << i << " ";
            }
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