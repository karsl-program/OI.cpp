#include <bits/stdc++.h>
#define int long long

const int N = 5e5 + 5;

std :: vector <int> g[N];
int n;
int top, f[N], stk[N], pre[N], fa[N];
std :: string s;

void dfs(int u) {
    int tmp = 0;
    if (s[u] == '(') stk[++ top] = u;
    else {
        if (top) tmp = stk[top --], f[u] = f[fa[tmp]] + 1;
    }
    pre[u] = pre[fa[u]] + f[u];
    for (int v : g[u]) dfs (v);
    if (tmp) stk[++ top] = tmp;
    else if (top) -- top;
}

namespace RunCode {
    void solve () {
        std :: cin >> n >> s; s = ' ' + s;
        for (int i = 2; i <= n; i ++) {
            int fai;
            std :: cin >> fai;
            g[fai].push_back (i);
            fa[i] = fai;
        }
        dfs (1);
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            ans ^= i * pre[i];
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