#include <bits/stdc++.h>

namespace RunCode {
    int f(int x) {
        int s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }
    void solve () {
        int N;
        std::cin >> N;
        int A[101];
        A[0] = 1;
        for (int i = 1; i <= N; ++i) {
            A[i] = 0;
            for (int j = 0; j < i; ++j) {
                A[i] += f(A[j]);
            }
        }
        std::cout << A[N] << '\n';
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/