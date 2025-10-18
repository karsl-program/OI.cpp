#include <bits/stdc++.h>
#define int long long
#define double long double
#define fi first
#define se second
using namespace std;
constexpr int N = 1e5 + 5;

int n, m, L, V, d[N], v[N], a[N], p[N], T, f[N];

pair <int, int> pos[N];

bool cmp (pair <int, int> a, pair <int, int> b) {
    if (a.fi == b.fi) return a.se > b.se;
    return a.fi < b.fi;
}

namespace RunCode {
    void solve () {
        for (int i = 1; i <= n; i ++) pos[i] = make_pair (0, 0);
        int tot = 0;
        std :: cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i ++) {
            std :: cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i ++) std :: cin >> p[i];
        for (int i = 1; i <= n; i ++) {
            pair <int, int> ap;
            if (a[i] > 0) {
                ap.se = m;

                double s = V * V - v[i] * v[i]; s /= 2.0 * a[i];
                s += d[i]; if (s > p[m]) continue;
                int k = lower_bound (p + 1, p + 1 + m, s) - p - 1;
                ap.fi = k;
            } else {
                if (v[i] <= V) continue;
                int k = lower_bound (p + 1, p + 1 + m, d[i]) - p - 1;
                ap.fi = k;

                int l = k, r = m, mid, ans = 0;
                while (l <= r) {
                    mid = (l + r) >> 1;
                    int kkk = v[i] * v[i] + 2 * a[i] * p[mid];
                    if (kkk > V * V) l = mid + 1, ans = mid;
                    else r = mid - 1;
                }
                if (ans < k) continue;
                ap.se = ans;
            }
            pos[++ tot] = ap;
        }
        std :: sort (pos + 1, pos + 1 + tot, cmp);
        int mr = 1e18;
        for (int i = tot; i; i --) {
            if (pos[i].se < mr) f[i] = 1;
            mr = std :: min (mr, pos[i].se);
        }
        int ans = 0, lst = -1;
        for (int i = 1; i <= tot; i ++) {
            if (f[i] && pos[i].fi > lst) ans ++, lst = pos[i].se;
            if (f[i]) f[i] = 0;
        }
        std :: cout << tot << " " << m - ans << '\n';
    }
}

signed main () {
    std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
    std :: cin >> T;
    while (T --) RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/