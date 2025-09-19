#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int a, b, c, cnt = 0;
        std :: cin >> a >> b >> c;
        for (int i = 0; i <= std :: min (10, a / 2); i ++) {
            for (int j = 0; j <= b; j ++) {
                for (int k = c / 2; k <= std :: min (j, c); k ++) {
                    if (i > j || i + k + j == 0) continue;
                    if ((k * k < i * j) && k != 0 && j != 0) continue;
                    // std :: cout << i << j << k << std :: endl;
                    cnt ++;
                }
            }
        }
        std :: cout << cnt;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/