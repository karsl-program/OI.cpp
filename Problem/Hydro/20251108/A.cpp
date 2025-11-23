#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e4 + 5, M = 2e4 + 5, inf = 1145141919810;

int n, m, dis[N], H, h[N], vis[N];

struct Node {
    int to, w;
};

std :: vector <Node> g[N];

namespace RunCode {
    void dij (int s) {
        for (int i = 1; i <= n; i ++) dis[i] = inf;
        dis[s] = 0;
        std :: priority_queue <std :: pair <int, int>, std :: vector <std :: pair <int, int>>, std :: greater <std :: pair <int, int>>> pq;
        pq.push ({0, s});
        while (!pq.empty ()) {
            int u = pq.top ().second;
            pq.pop ();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto v : g[u]) {
                int to = v.to, w = v.w;
                if (vis[to]) continue;
                if (dis[to] > dis[u] + w) {
                    dis[to] = dis[u] + w;
                    pq.push ({dis[to], to});
                }
            }
        }
    }

    // void _dij (int s) {
    //     int k = 0;
    //     memset (dis, 0x3f, sizeof (dis));
    //     dis[s] = 0;
    //     std :: priority_queue <std :: pair <int, int>, std :: vector <std :: pair <int, int>>, std :: greater <std :: pair <int, int>>> pq;
    //     pq.push ({0, s});
    //     while (!pq.empty ()) {
    //         int u = pq.top ().second;
    //         pq.pop ();
    //         if (dis[u] != pq.top ().first) continue;
    //         for (auto v : g[u]) {
    //             int to = v.to, w = v.w;
    //             if (dis[to] > dis[u] + w) {
    //                 dis[to] = dis[u] + w;
    //                 k += h[to] - h[u];
    //                 pq.push ({dis[to], to});
    //             }
    //         }
    //     }
    // }

    void print () {
        for (int i = 2; i <= n; i ++) {
            if (dis[i] == inf) {
                std :: cout << -1 << ' ';
            } else {
                std :: cout << dis[i] << ' ';
            }
        }
    }

    void _solve1 () {
        dij (1);
        print ();
    }

    void solve () {
        std :: cin >> n >> m >> H;
        for (int i = 1; i <= n; i ++) std :: cin >> h[i];
        for (int i = 1; i <= m; i ++) {
            int u, v, w;
            std :: cin >> u >> v >> w;
            g[u].push_back ({v, w});
            g[v].push_back ({u, w});
        }
        // int f = h[1];
        // for (int i = 2; i <= n; i ++) {
        //     if (f != h[i]) goto con1;
        // }
        _solve1 ();
        // return ;
        // con1: {}
    }
}

signed main () {
    std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
    freopen ("climb.in", "r", stdin);
    freopen ("climb.out", "w", stdout);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/
