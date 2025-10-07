#include <bits/stdc++.h>

const int N = 2e5 + 5, X = 1e6 + 5;

struct Node {
    int l, r, wid, num;
} tree[N << 2];

int n, m, pos[X];

void pushup (int u) {
    if (tree[u << 1].l) tree[u].l = tree[u << 1].l;
    else tree[u].l = tree[u << 1 | 1].l;
    
    if (tree[u << 1 | 1].r) tree[u].r = tree[u << 1 | 1].r;
    else tree[u].r = tree[u << 1].r;

    tree[u].wid = tree[u << 1].wid;
    tree[u].num = tree[u << 1].num;

    if (tree[u << 1 | 1].l && tree[u << 1].r) {
        if ((tree[u << 1 | 1].l - tree[u << 1].r) / 2 > tree[u].wid) {
            tree[u].wid = (tree[u << 1 | 1].l - tree[u << 1].r) / 2;
            tree[u].num = (tree[u << 1 | 1].l + tree[u << 1].r) / 2;
        }
    }
    
    if (tree[u << 1 | 1].wid > tree[u].wid) {
        tree[u].wid = tree[u << 1 | 1].wid;
        tree[u].num = tree[u << 1 | 1].num;
    }
}

void update (int u, int l, int r, int x, int op) {
    if (l == r) {
        if (op == 1) {
            tree[u] = {l, r, 0, 0};
            return;
        } else {
            tree[u] = {0, 0, 0, 0};
            return;
        }
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update (u << 1, l, mid, x, op);
    else update (u << 1 | 1, mid + 1, r, x, op);
    pushup (u);
}

#define cin(x, y) scanf ("%d%d", &x, &y);

namespace RunCode {
    void solve () {
        cin(n, m);
        for (int i = 1; i <= m; i ++) {
            int op, x;
            cin(op, x);
            if(op == 1) {
                int ans; 
                auto rt = tree[1];
                if(rt.l == 0) update(1, 1, n, pos[x] = 1, true), ans = 1;
                else {
                    int v = 0;
                    if(v < rt.l - 1) v = rt.l - 1, ans = 1;
                    if(v < rt.wid) v = rt.wid, ans = rt.num;
                    if(v < n - rt.r) v = n - rt.r, ans = n; 
                    update(1, 1, n, pos[x] = ans, true);
                }
                printf("%d ", ans);
            }
            else {
                update(1, 1, n, pos[x], false);
                pos[x] = 0;
            }
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