#include <bits/stdc++.h>

#define int long long

const int N = 2e5 + 5;
int tree[N], last[N], n;

void upd (int x, int u) {
    for (int i = x; i <= n; i += (i & -i)) tree[i] += u;
}

int qry (int x) {
    int res = 0;
    for (int i = x; i; i -= (i & -i)) res += tree[i];
    return res;
}

namespace RunCode {
    void solve () {
        int ans = 0;
        std :: cin >> n;
        for (int i = 1; i <= n; i ++) {
            int x;
            std :: cin >> x;
            if (last[x]) upd (last[x], -1);
            upd (i, 1);
            ans += qry (i - 1) - qry (last[x]);
            last[x] = i;
        }
        std :: cout << ans;
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/