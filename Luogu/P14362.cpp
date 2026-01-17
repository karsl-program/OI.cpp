#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e5 + 15, M = 5e6 + 5;
int n, m, k, tot, ci[15], c[15][N], f[N], u, v, w;
vector <int> use;
struct Edge {
    int u, v, w;
}e[M];

int find (int x) {
    if (f[x] == x) return x;
    return f[x] = find (f[x]);
}

void merge (int x, int y) {
    int rt = find (x), rt1 = find (y);
    f[rt1] = rt;
}

namespace RunCode {
    bool cmp (Edge a, Edge b) {
        return a.w < b.w;
    }

    void solve () {
        cin >> n >> m >> k;
        for (int i = 1; i <= m; i ++) {
            cin >> u >> v >> w;
            e[i] = {u, v, w};
        }
        int yuann = n;
        for (int i = 1; i <= k; i ++) {
            cin >> ci[i];
            for (int j = 1; j <= yuann; j ++) {
                cin >> c[i][j];
            }
            if (!ci[i]) {
                ++ n;
                for (int j = 1; j <= yuann; j ++) e[++ m] = {j, n, c[i][j]};
            } else use.push_back (i);
        }
        k = use.size ();
        int ans = 1e18;
        for (int bin = 0; bin < (1 << k); bin ++) {
            int res = 0, ttt = 0, cnt = m, cntn = n;
            tot = 0;
            for (int rrr = 0; rrr < k; rrr ++) {
                if ((bin >> rrr) & 1) {
                    ttt += ci[use[rrr]];
                    ++ cntn;
                    for (int i = 1; i <= yuann; i ++) {
                        e[++ cnt] = {i, cntn, c[use[rrr]][i]};
                    }
                }
            }
            sort (e + 1, e + cnt + 1, cmp);
            for (int i = 1; i <= cntn; i ++) f[i] = i;
            for (int i = 1; i <= cnt; i ++) {
                if (tot == cntn - 1) break;
                if (find (e[i].u) != find (e[i].v)) {
                    merge (e[i].u, e[i].v);
                    res += e[i].w, tot ++;
                }
            }
            ans = min (ans, res + ttt);
        }
        cout << ans << '\n';
    }
}

signed main () {
    ios :: sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/