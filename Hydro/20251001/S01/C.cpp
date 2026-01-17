#include <bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, inf = 1e18;
int n, k;
std :: vector <std :: pair <int, int>> g[N];
bool isk[N];
int kcnt[N], siz[N], ma[N], ma2[N], maxx[N], dis[N];

namespace RunCode {
    void dfs1 (int u, int fa) {
        kcnt[u] = isk[u];
        ma[u] = ma2[u] = -inf;
        if (isk[u]) ma[u] = 0;
        
        for (auto &[v, w] : g[u]) {
            if (v == fa) continue;
            
            dfs1(v, u);
            kcnt[u] += kcnt[v];
            
            int dist = ma[v] + w;
            if (dist > ma[u]) {
                ma2[u] = ma[u];
                ma[u] = dist;
            } else if (dist > ma2[u]) {
                ma2[u] = dist;
            }
        }
    }

    void calc (int u, int fa) {
        for (auto &[v, w] : g[u]) {
            if (v == fa) continue;
            
            calc(v, u);
            if (kcnt[v] > 0) {
                siz[1] += w;
            }
        }
    }

    void dfs2 (int u, int fa) {
        for (auto &[v, w] : g[u]) {
            if (v == fa) continue;
            
            siz[v] = siz[u];
            if (kcnt[v] > 0) {
                siz[v] -= w;
            }
            if (k - kcnt[v] > 0) {
                siz[v] += w;
            }
            
            maxx[v] = -inf;
            if (maxx[u] != -inf) {
                maxx[v] = std :: max (maxx[v], maxx[u] + w);
            }
            
            if (ma[v] + w == ma[u]) {
                if (ma2[u] != -inf) {
                    maxx[v] = std :: max (maxx[v], ma2[u] + w);
                }
            } else {
                if (ma[u] != -inf) {
                    maxx[v] = std :: max (maxx[v], ma[u] + w);
                }
            }
            
            dfs2(v, u);
        }
        
        dis[u] = std :: max(ma[u], maxx[u]);
    }

    void solve () {
        freopen ("rescue.in", "r", stdin);
        freopen ("rescue.out", "w", stdout);

        std :: ios :: sync_with_stdio (false);
        std :: cin.tie (0), std :: cout.tie (0);
        
        std :: cin >> n >> k;
        
        for (int i = 1; i < n; i++) {
            int u, v, w;
            std :: cin >> u >> v >> w;
            g[u].push_back ({v, w});
            g[v].push_back ({u, w});
        }
        
        for (int i = 1; i <= k; i++) {
            int x;
            std :: cin >> x;
            isk[x] = true;
        }
        
        dfs1 (1, 0);
        calc (1, 0);
        
        maxx[1] = -inf;
        dfs2 (1, 0);
        
        for (int i = 1; i <= n; i++) {
            int res = 2 * siz[i] - dis[i];
            std :: cout << res << "\n";
        }
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/