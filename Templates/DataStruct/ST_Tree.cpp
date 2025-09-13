#include <bits/stdc++.h>

struct ST {
    int n;
    std :: vector <int> tree, lz;

    ST (int siz) {
        n = siz;
        siz <<= 2, tree.resize (siz), lz.resize (siz);
    }

    void pushup (int p) {
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    void pushdown (int p, int l, int r) {
        if (lz[p]) {
            int mid = (l + r) >> 1;
            tree[p << 1] += lz[p] * (mid - l + 1);
            tree[p << 1 | 1] += lz[p] * (r - mid);
            lz[p << 1] += lz[p], lz[p << 1 | 1] += lz[p];
            lz[p] = 0;
        }
    }

    void build (int p, int l, int r, int *a) {
        if (l == r) return (void)(tree[p] = a[l]);
        int mid = (l + r) >> 1;
        build (p << 1, l, mid, a), build (p << 1 | 1, mid + 1, r, a);
        pushup (p);
    }

    void upd (int p, int l, int r, int pl, int pr, int k) {
        if (pl <= l && r <= pr) {
            tree[p] += k * (r - l + 1);
            lz[p] += k;
            return;
        }
        int mid = (l + r) >> 1;
        pushdown (p, l, r);
        if (pl <= mid) upd (p << 1, l, mid, pl, pr, k);
        if (pr > mid) upd (p << 1 | 1, mid + 1, r, pl, pr, k);
        pushup (p);
    }

    int qry (int p, int l, int r, int pl, int pr) {
        if (pl <= l && r <= pr) return tree[p];
        int mid = (l + r) >> 1;
        pushdown (p, l, r);
        int res = 0;
        if (pl <= mid) res += qry (p << 1, l, mid, pl, pr);
        if (pr > mid) res += qry (p << 1 | 1, mid + 1, r, pl, pr);
        return res;
    }
};

const int N = 1e5 + 5;
int a[N];

namespace RunCode {
    void solve () {
        int n;
        std :: cin >> n;
        ST st (n);
        for (int i = 1; i <= n; i ++) std :: cin >> a[i];
        st.build (1, 1, n, a);
        int q;
        std :: cin >> q;
        while (q --) {
            int op, x, y, k;
            std :: cin >> op >> x >> y;
            if (op == 1) {
                std :: cin >> k;
                st.upd (1, 1, n, x, y, k);
            } else {
                std :: cout << st.qry (1, 1, n, x, y) << '\n';
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