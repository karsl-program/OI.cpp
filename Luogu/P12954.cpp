#include <bits/stdc++.h>
#define int long long

constexpr int MAXN = 2e5 + 5;
int N, L, global;
std :: vector <int> g[MAXN];

int dfn[MAXN], low[MAXN], times, root;

bool cut[MAXN];

namespace RunCode {
    void tarjan (int x) {
        dfn[x] = low[x] = ++ times;
        for (int v : g[x]) {
            if (!dfn[v]) {
                tarjan (v);
                low[x] = std :: min (low[x], low[v]);
                if (low[v] >= dfn[x]) cut[x] = true;
            } else {
                low[x] = std :: min (low[x], dfn[v]);
            }
        }
    }

    void solve () {
        std :: memset (dfn, 0, sizeof dfn);
        std :: memset (low, 0, sizeof low);
        std :: memset (cut, false, sizeof cut);
        times = 0;
        std :: cin >> N >> L;
        for (int i = 1; i <= L; i ++) {
            int K;
            std :: cin >> K;
            for (int j = 1; j <= K; j ++) {
                int u; std :: cin >> u;
                g[i + N].push_back (u);
                g[u].push_back (i + N);
            }
        }
        for (int i = 1; i <= N; i ++) {
            if (!dfn[i]) tarjan (i);
        }

        int ans = 0;
        for (int i = N + 1; i <= N + L; i ++) {
            if (cut[i]) ans ++;
        }
        for (int i = 1; i <= N + L; i ++) g[i].clear ();
        std :: cout << "Case #" << global << ": " << ans << '\n';
    }
}

signed main () {
    std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
    int TTT; std :: cin >> TTT; while (++ global, TTT --)
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/