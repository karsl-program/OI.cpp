#include <bits/stdc++.h>

namespace RunCode {
    const int MAXN = 100005;
    int n, q;
    int p[MAXN];
    int depth[MAXN];
    int anc[MAXN][20];
    void pre() {
        for (int i = 1; i <= n; i++) {
            depth[i] = -1;
            for (int j = 0; j < 20; j++) {
                anc[i][j] = 0;
            }
        }
        int root = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i] == 0) {
                root = i;
                break;
            }
        }
        
        std::queue<int> que;
        que.push(root);
        depth[root] = 0;
        anc[root][0] = root;
        
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            
            for (int v = 1; v <= n; v++) {
                if (p[v] == u) {
                    depth[v] = depth[u] + 1;
                    anc[v][0] = u;
                    que.push(v);
                }
            }
        }
        
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if (anc[i][j-1] != 0) {
                    anc[i][j] = anc[anc[i][j-1]][j-1];
                }
            }
        }
    }
    
    int lca(int x, int y) {
        if (depth[x] < depth[y]) std::swap(x, y);
        
        int diff = depth[x] - depth[y];
        for (int i = 0; diff; i++, diff >>= 1) {
            if (diff & 1) {
                x = anc[x][i];
            }
        }
        
        if (x == y) return x;
        
        for (int i = 19; i >= 0; i--) {
            if (anc[x][i] != 0 && anc[x][i] != anc[y][i]) {
                x = anc[x][i];
                y = anc[y][i];
            }
        }
        
        return anc[x][0];
    }
    
    void solve() {
        freopen("decode.in", "r", stdin);
        freopen("decode.out", "w", stdout);
        
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
        }
        
        pre();
        
        std::vector<long long> L;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                long long val = (1LL * (x - 1) * n * n + 1LL * (lca(x, y) - 1) * n + 1LL * (y - 1));
                L.push_back(val);
            }
        }
        
        std::sort(L.begin(), L.end());
        
        for (int i = 0; i < q; i++) {
            int pos;
            scanf("%d", &pos);
            printf("%lld\n", L[pos - 1]);
        }
    }
}

int main() {
    RunCode::solve();
    return 0;
}

/*
Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth
*/