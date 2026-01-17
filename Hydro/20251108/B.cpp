#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5 + 5;
int n, f = 1, f1 = 1;
vector <int> g[N];

namespace RunCode {
    void solve () {
        std :: cin >> n;
        for (int i = 1; i < n; i ++) {
            int u, v;
            std :: cin >> u >> v;
            g[u].push_back (v);
            g[v].push_back (u);
            if (u != i || v != i + 1) f = 0;
            if (u != 1) f1 = 0;
        }
        if (f == 1) {
            for (int i = 1; i <= n; i ++) {
                cout << n * (n + 1) / 2 << endl;
            }
        } else if (f1 == 1) {
            for (int i = 1; i <= n; i ++) {
                cout << n * (n + 1) / 2 << endl;
            }
        }
    }
}

signed main () {
    freopen ("slca.in", "r", stdin);
    freopen ("slca.out", "w", stdout);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/