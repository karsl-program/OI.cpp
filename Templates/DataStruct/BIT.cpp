#include <bits/stdc++.h>

struct BIT {
    int n;
    std :: vector <int> tree;

    BIT (int siz) {
        n = siz, tree.resize (siz + 1);
    }

    #define lowbit(x) (x & -x)

    void upd (int x, int val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += val;
        }
    }

    int qry (int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) {
            res += tree[i];
        }
        return res;
    }

    #undef lowbit
};

namespace RunCode {
    void solve () {
        int n; std :: cin >> n;
        BIT a (n);
        for (int i = 0; i < n; i ++) {
            int x; std :: cin >> x;
            a.upd (i + 1, x);
        }
        int q; std :: cin >> q;
        while (q --) {
            int op, x, y;
            std :: cin >> op >> x >> y;
            if (op == 1) {
                a.upd (x, y);
            } else {
                std :: cout << a.qry (y) - a.qry (x - 1) << '\n';
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