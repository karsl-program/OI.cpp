#include <bits/stdc++.h>
#define fi first
#define se second
constexpr int N = 5e5 + 5;
int n, m, u, v, cnt, dfn[N], times, low[N], tot, is_b[N];
std :: vector <std :: pair <int, int>> e[N];
std :: stack <int> stk;
int out[N], res, id[N];

namespace RunCode {
    void tarjan (int x, int from) {
        dfn[x] = low[x] = ++ times;
        stk.push (x);
        for (auto to : e[x]) {
            if (!dfn[to.fi]) {
                tarjan (to.fi, to.se);
                low[x] = std :: min (low[x], low[to.fi]);
                if (low[to.fi] > dfn[x]) {
                    is_b[to.se] = is_b[to.se ^ 1] = 1;
                }
            } else if (to.se != (from ^ 1)) {
                low[x] = std :: min (low[x], dfn[to.fi]);
            }
        }
        if (low[x] == dfn[x]) {
            int y;
            ++ tot;
            do {
                y = stk.top ();
                stk.pop ();
                id[y] = tot;
            } while (y != x);
        }
    }

    void solve () {
        std :: cin >> n >> m;
        while (m --) {
            std :: cin >> u >> v;
            e[u].push_back ({v, cnt ++});
            e[v].push_back ({u, cnt ++});
        }
        for (int i = 1; i <= n; i ++) {
            if (!dfn[i]) { tarjan (i, -1); }
        }
        // std :: cout << tot << '\n';
        // for (int i = 1; i <= tot; i ++) {
        //     std :: cout << ans[i].size () << ' ';
        //     for (int j : ans[i]) {
        //         std :: cout << j << ' ';
        //     }
        //     std :: cout << '\n';
        // }
        for (int i = 1; i <= n; i ++) {
            for (auto j : e[i]) {
                if (is_b[j.se]) {
                    out[id[i]] ++;
                }
            }
        }
        for (int i = 1; i <= tot; i ++) {
            res += (out[i] == 1);
        }
        std :: cout << ((res + 1) >> 1) << '\n';
    }
}

int main () {
    std :: ios :: sync_with_stdio (false);
    std :: cin.tie (0), std :: cout.tie (0);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/