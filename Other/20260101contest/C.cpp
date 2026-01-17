#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, op;
constexpr int N = 1e5 + 5, MOD = 1e9 + 7;
// int L[N], R[N];
struct Pos {
    int l, r;
} pos[N];

bool cmp (Pos a, Pos b) {
    if (a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}
namespace RunCode {
    void solve () {
        cin >> n >> op;
        int ll = MOD, rr = 0;
        for (int i = 1; i <= n; i ++) {
            cin >> pos[i].l >> pos[i].r;
            ll = min (ll, pos[i].r);
            rr = max (rr, pos[i].l);
        }
        cout << max (0ll, rr - ll) << ' ';
        if (op == 2) {
            int h = 1;
            if (rr - ll <= 0) {
                cout << ll - rr + 1;
                return ;
            }
            for (int i = 1; i <= n; i ++) {
                // if (min (pos[i].r, rr) - max (pos[i].l, ll) < 0) continue;
                h *= max (0ll, min (pos[i].r, rr) - max (pos[i].l, ll)) + 1;
                h += MOD, h %= MOD;
            }
            cout << h << endl;
        }
    }
}

signed main () {
    ios :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/