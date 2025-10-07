#include <bits/stdc++.h>

/*

01 0000
02 0001   ceil(n / 1) % 2 == 0 第一位 + n % 1 + n / 2
03 0010
04 0011   ceil(n / 2) % 2 == 0  第二位 + n % 2 + n / 2
05 0100
06 0101
07 0110
08 0111   ceil(n / 4) % 2 == 0 第三位 + n % 4 + n / 2
09 1000
10 1001
11 1010
12 1011
13 1100
14 1101
15 1110
16 1111

n >> 1 & 1
n >> 2 & 1
n >> 3 & 1

*/

namespace RunCode {
    void solve () {
        long long n; std :: cin >> n;
        if (n % 4 == 0) std :: cout << 0 << std :: endl;
        else if (n % 4 == 1) std :: cout << n << std :: endl;
        else if (n % 4 == 2) std :: cout << 1 << std :: endl;
        else if (n % 4 == 3) std :: cout << n + 1 << std :: endl;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/