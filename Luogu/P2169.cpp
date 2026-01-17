#include <bits/stdc++.h>

constexpr int N = 2e5 + 5, M = 1e6 + 5;
int low[N], dfn[N], instk[N], stk[N], top, scc[N], scnt, times;
int head[N], k;
struct Edge {
    int next, to, w;
} e[M << 1];

struct Node {
    int w, to;
    bool operator < (const Node &o) const {
        return w > o.w;
    }
};

std :: vector <Node> g[N];

int dis[N];

namespace RunCode {
    void tarjan (int x) {
        dfn[x] = low[x] = ++ times;
        instk[x] = true;
        stk[++ top] = x;
        for (int i = head[x]; i; i = e[i].next) {
            int y = e[i].to;
            if (!dfn[y]) {
                tarjan (y);
                low[x] = std :: min (low[x], low[y]);
            } else if (instk[y]) {
                low[x] = std :: min (low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x]) {
            ++ scnt;
            int y;
            do {
                y = stk[top --];
                instk[y] = false;
                scc[y] = scnt;
            } while (y != x);
        }
    }

    void dij (int s) {
        std :: memset (dis, 0x3f, sizeof (dis));
        dis[s] = 0;
        std :: priority_queue <Node> q;
        q.push ({0, s});
        while (!q.empty ()) {
            int x = q.top ().to;
            q.pop ();
            if (dis[x] != q.top ().to) {
                continue;
            }
            for (int i = 0; i < g[x].size (); i ++) {
                int y = g[x][i].to, w = g[x][i].w;
                if (dis[y] > dis[x] + w) {
                    dis[y] = dis[x] + w;
                    q.push ({dis[y], y});
                }
            }
        }
    }

    void solve () {
        int n, m;
        std :: cin >> n >> m;
        for (int i = 1; i <= m; i ++) {
            int u, v, w;
            std :: cin >> u >> v >> w;
            e[++ k] = {head[u], v, w};
            head[u] = k;
        }
        for (int i = 1; i <= n; i ++) {
            if (!dfn[i]) {
                tarjan (i);
            }
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = head[i]; j; j = e[j].next) {
                int y = e[j].to;
                if (scc[i] != scc[y]) {
                    g[scc[i]].push_back ({e[j].w, scc[y]});
                }
            }
        }
        dij (scc[1]);
        std :: cout << dis[scc[n]] << '\n';
    }
}

int main () {
    std :: ios :: sync_with_stdio (false);
    std :: cin.tie (0);
    std :: cout.tie (0);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/