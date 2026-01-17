#include <bits/stdc++.h>
#define int long long
const int MAX_N = 105;
const int INF = 1e18;
namespace RunCode {
    void solve () {
        int n, m;
        std :: cin >> n >> m;
        std :: vector<std :: tuple<int, int, int>> edges;
        int dist[MAX_N][MAX_N];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }

        for (int i = 0; i < m; i++) {
            int u, v, w;
            std :: cin >> u >> v >> w;
            edges.push_back({u, v, w});
            if (w < dist[u][v]) {
                dist[u][v] = w;
                dist[v][u] = w;
            }
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        if (dist[i][j] > dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (auto& e : edges) {
            int u = std :: get<0>(e);
            int v = std :: get<1>(e);
            int w = std :: get<2>(e);
            if (w > dist[u][v]) {
                ans++;
            }
        }
        std :: cout << ans << std :: endl;
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/