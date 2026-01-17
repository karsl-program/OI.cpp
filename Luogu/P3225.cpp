#include <bits/stdc++.h>
#define int long long

int n, m, root;
constexpr int N = 1e3 + 5;
int low[N], dfn[N], times;
std :: stack <int> stk;
int dcc_cnt, global;
std :: vector <int> dcc[N];
int k, cut[N], head[N];

struct Edge {
    int to, nxt;
} e[N << 1];

namespace RunCode {
    void tarjan (int x) {
        dfn[x] = low[x] = ++ times;
        stk.push (x);
        int cnt = 0;
        for (int i = head[x]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (!dfn[v]) {
                tarjan (v);
                low[x] = std :: min (low[x], low[v]);

                if (low[v] >= dfn[x]) {
                    cnt ++;
                    if (x != root || cnt > 1) cut[x] = true;
                    dcc_cnt ++;
                    int y;
                    do {
                        y = stk.top ();
                        stk.pop ();
                        dcc[dcc_cnt].push_back (y);
                    } while (y != v);
                    dcc[dcc_cnt].push_back (x);
                }
            } else {
                low[x] = std :: min (low[x], dfn[v]);
            }
        }
   }

    void solve () {
        std :: memset (head, -1, sizeof head);
        std :: memset (dfn, 0, sizeof dfn);
        std :: memset (cut, 0, sizeof cut);
        dcc_cnt = k = times = 0;
        for (int i = 1; i <= m; i ++) {
            int u, v; std :: cin >> u >> v;
            n = std :: max ({n, u, v});
            e[++ k].to = v, e[k].nxt = head[u], head[u] = k;
            e[++ k].to = u, e[k].nxt = head[v], head[v] = k;
        }
        for (int i = 1; i <= n; i ++) {
            if (!dfn[i]) {
                root = i; tarjan (i);
            }
        }
        unsigned int num = 1, _ans = 0;
        for (int i = 1; i <= dcc_cnt; i ++) {
            int _cnt = 0;
            for (auto v : dcc[i]) {
                if (cut[v]) _cnt ++;
            }
            if (_cnt == 0 && dcc[i].size () > 1) _ans += 2, num *= (dcc[i].size () * (dcc[i].size () - 1)) >> 1;
            else if (_cnt == 1) _ans ++, num *= dcc[i].size () - 1;
            else if (dcc[i].size () == 1) _ans ++;
            dcc[i].clear ();
        }
        std :: cout << "Case " << global << ": " << _ans << " " << num << "\n";
    }
}

signed main () {
    std :: ios :: sync_with_stdio (false);
    std :: cin.tie (0), std :: cout.tie (0);
    while (std :: cin >> m, ++ global, m)
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/