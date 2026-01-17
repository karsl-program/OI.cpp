#include <bits/stdc++.h>

const int N = 1e3 + 5;

int ans, n, m;
bool vis[N];

std :: vector <int> g[N];

void dfs (int x, int dep, int fa) {
    if (dep == 4) {ans ++; return;}
    if (dep > 1) vis[x] = 1;
    for (auto v : g[x]) {
        if (vis[v] || v == fa) continue;
        dfs (v, dep + 1, x);
    }
    vis[x] = 0;
}

namespace RunCode {
    void solve () {
        std :: cin >> n >> m;
        for (int i = 1; i <= m; i ++) {
            int u, v;
            std :: cin >> u >> v;
            g[u].push_back (v);
            g[v].push_back (u);
        }
        for (int i = 1; i <= n; i ++) {
            dfs (i, 1, 0);
        }
        std :: cout << ans;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/