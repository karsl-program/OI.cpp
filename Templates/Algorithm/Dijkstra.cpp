#include <bits/stdc++.h>

const int N = 1e5 + 5;

int n, m, s, dis[N];

struct Edge {
    int to, w;
};

std :: vector <Edge> g[N];

namespace RunCode {
    void dij (int s) {
        std :: memset (dis, 0x3f, sizeof dis);
        dis[s] = 0;
        std :: priority_queue <std :: pair <int, int>, std :: vector <std :: pair <int, int> >, std :: greater <std :: pair <int, int> > > q;
        q.push ({0, s});
        while (q.size ()) {
            int u = q.top ().second;
            q.pop ();
            for (auto v : g[u]) {
                int w = v.w, to = v.to;
                if (dis[to] > dis[u] + w) {
                    dis[to] = dis[u] + w;
                    q.push ({dis[to], to});
                }
            }
        }
    }

    void solve () {
        std :: cin >> n >> m >> s;
        for (int i = 1; i <= m; i ++) {
            int u, v, w;
            std :: cin >> u >> v >> w;
            g[u].push_back ({v, w});
            g[v].push_back ({u, w});
        }
        dij (s);
        for (int i = 1; i <= n; i ++) {
            std :: cout << dis[i] << " ";
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