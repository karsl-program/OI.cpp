#include <bits/stdc++.h>
const int N = 7e6 + 5;
int ts[N][25], n, l, r, P, lg2[N];
long long pre[N];

namespace RunCode {
    void add (int x, int pos) {
        ts[pos][0] = x;
        for (int i = 1; (1 << i) <= pos; ++ i) {
            ts[pos][i] = std :: max (ts[pos][i - 1], ts[pos - (1 << (i - 1))][i - 1]);
        }
    }

    void solve () {
        std :: ios :: sync_with_stdio (false);
        std :: cin.tie (0);
        int T;
        std :: cin >> T;
        lg2[1] = 0;
        for (int i = 2; i < N; ++ i) {
            lg2[i] = lg2[i >> 1] + 1;
        }
        while (T --) {
            int op;
            std :: cin >> op >> l;
            if (-- op) {
                std :: cin >> r;
                if (op & 1) P ^= pre[r] - pre[l - 1];
                else {
                    int k = lg2[r - l + 1];
                    P ^= std :: max (ts[r][k], ts[l + (1 << k) - 1][k]);
                }
            } else {
                add (l, ++ n), pre[n] = pre[n - 1] + l;
            }
        }
        std :: cout << P;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/