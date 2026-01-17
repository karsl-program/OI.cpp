#include <bits/stdc++.h>

const int N = 1e5 + 5;

int dfn[N], low[N], siz[N], tot, stk[N], top, n, m, times, inst[N];
std :: vector <int> g[N];

void add (int x, int y) { g[x].push_back (y); }

void tarjan (int x) {
    dfn[x] = low[x] = ++ times;
    stk[++ top] = x, inst[x] = true;
    for (int to : g[x]) {
        if (!dfn[to]) {
            tarjan (to), low[x] = std :: min (low[x], low[to]);
        } else if (inst[to]) {
            low[x] = std :: min (low[x], dfn[to]);
        }
    }

    if (dfn[x] == low[x]) {
        int cur;
        ++ tot;
        do {
            cur = stk[top --];
            siz[tot] ++, inst[cur] = false;
        } while (cur != x);
    }
}

namespace RunCode {
    void solve () {
        std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
        std :: cin >> n >> m;
        for (int i = 1; i <= m; i ++) {
            int a, b; std :: cin >> a >> b; add (a, b);
        }
        for (int i = 1; i <= n; i ++) {
            if (!dfn[i]) tarjan (i);
        }
        int ans = 0;
        for (int i = 1; i <= tot; i ++) {
            if (siz[i] > 1) ans ++;
        }
        std :: cout << ans << std :: endl;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/