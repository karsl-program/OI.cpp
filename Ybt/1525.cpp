#include <bits/stdc++.h>

constexpr int N = 1e4 + 5;

struct Edge {
    int to, nxt;
} e[N << 2];

int head[N], k, cnt, dfn[N], low[N], top, kcnt, times, n, m, root;

namespace RunCode {
    void tarjan (int x) {
        int tcnt = 0;
        times ++;
        dfn[x] = low[x] = times;
        for (int i = head[x]; ~i; i = e[i].nxt) {
            int y = e[i].to;
            if (!dfn[y]) {
                tarjan (y);
                low[x] = std :: min (low[x], low[y]);
                if (low[y] >= dfn[x]) {
                    tcnt ++;
                }
            }
            else {
                low[x] = std :: min (low[x], dfn[y]);
            }
        }
        if (x != root && tcnt) tcnt ++;
        k = std :: max (tcnt, k);
    }

    void solve () {
        cnt = kcnt = times = k = top = 0;
        std :: memset (head, -1, sizeof head);
        std :: memset (dfn, 0, sizeof dfn);
        // std :: memset (low, 0, sizeof low);
        for (int i = 1; i <= m; i ++) {
            int u, v; std :: cin >> u >> v;
            ++ u, ++ v;
            e[++ cnt] = {v, head[u]}, head[u] = cnt;
            e[++ cnt] = {u, head[v]}, head[v] = cnt;
        }
        for (int i = 1; i <= n; i ++) {
            if (!dfn[i]) root = i, tarjan (i), kcnt ++;
        }
        std :: cout << kcnt + k - 1 << std :: endl;
    }
}

int main () {
    std :: ios :: sync_with_stdio (false);
    std :: cin.tie (nullptr), std :: cout.tie (nullptr);
    while (std :: cin >> n >> m, n || m)
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/