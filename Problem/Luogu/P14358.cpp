#include <bits/stdc++.h>
#define pii pair <int, int>
#define fi first
#define se second
using namespace std;
constexpr int N = 105;
int n, m; pii a[N];
#define getx(x) ((x - 1) % n + 1)
#define gety(x) ((x + n - 1) / n)

bool cmp (pii a, pii b) {
    return a.fi > b.fi;
}

namespace RunCode {
    void solve () {
        cin >> n >> m;
        for (int i = 1; i <= n * m; i ++) cin >> (a[i].fi), a[i].se = i;
        sort (a + 1, a + n * m + 1, cmp);
        for (int i = 1; i <= n * m; i ++) {
            if (a[i].se == 1) {
                if (gety (i) & 1); else {
                    cout << gety (i) << ' ' << n - getx (i) + 1 << '\n';
                    return ;
                }
                cout << gety (i) << ' ' << getx (i) << '\n';
                return ;
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