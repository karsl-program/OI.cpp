#include <bits/stdc++.h>

const int N = 2e5 + 5;
int n, to[N], d[N], vis[N], ans = 1e9;

void dfs (int x, int dep) {
    if (vis[x]) return ans = std :: min (ans, dep), void ();
    vis[x] = 1; dfs (to[x], dep + 1);
}

namespace RunCode {
    void solve () {
        std :: cin >> n;
        for (int i = 1; i <= n; i ++) {
            std :: cin >> to[i]; d[to[i]] ++;
        }
        std :: queue <int> q;
        for (int i = 1; i <= n; i ++) if (!d[i]) q.push (i);
        while (!q.empty ()) {
            int u = q.front (); q.pop ();
            vis[u] = 1, d[to[u]] --; if (!d[to[u]]) q.push (to[u]);
        }
        for (int i = 1; i <= n; i ++) {
            if (!vis[i]) dfs (i, 0);
        }
        std :: cout << ans << '\n';
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/