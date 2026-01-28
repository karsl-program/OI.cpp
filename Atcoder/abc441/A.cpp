#include <bits/stdc++.h>
#define int long long

namespace RunCode {

    struct Node {
        int fupm = 0;
        int fdnm = 0;
        int fupc = 1;
        int fdnc = 0;
        int laz = 0;
        bool lzfl = false;
        
        Node comb (const Node & left, const Node & right) {
            Node res;
            res.fupm = std :: max (left.fupm, right.fupm);
            res.fdnm = std :: max (left.fdnm, right.fdnm);
            res.fupc = left.fupc + right.fupc;
            res.fdnc = left.fdnc + right.fdnc;
            return res;
        }
    };

    std :: vector<Node> tree;
    int n;

    void appa (Node & node, int x) {
        if (node.fupc > 0) {
            node.fupm += x;
        }
        node.laz += x;
    }

    void appf (Node & node) {
        std :: swap (node.fupm, node.fdnm);
        std :: swap (node.fupc, node.fdnc);

        if (node.fupm > 0) node.fupm = 0;
        if (node.fdnm > 0) node.fdnm = 0;

        node.lzfl = !node.lzfl;
        node.laz = 0;
    }

    void push (int idx, int l, int r) {
        if (tree[idx].lzfl) {
            appf (tree[idx * 2]);
            appf (tree[idx * 2 + 1]);
            tree[idx].lzfl = false;
        }

        if (tree[idx].laz != 0) {
            appa (tree[idx * 2], tree[idx].laz);
            appa (tree[idx * 2 + 1], tree[idx].laz);
            tree[idx].laz = 0;
        }
    }

    void bld (int idx, int l, int r) {
        if (l == r) {
            tree[idx] = Node ();
            return;
        }
        int mid = (l + r) / 2;
        bld (idx * 2, l, mid);
        bld (idx * 2 + 1, mid + 1, r);
        tree[idx] = tree[idx].comb (tree[idx * 2], tree[idx * 2 + 1]);
    }

    void typ1 (int idx, int l, int r, int L, int R, int X) {
        if (L > r || R < l) return;
        if (L <= l && r <= R) {
            appa (tree[idx], X);
            return;
        }
        push (idx, l, r);
        int mid = (l + r) / 2;
        typ1 (idx * 2, l, mid, L, R, X);
        typ1 (idx * 2 + 1, mid + 1, r, L, R, X);
        tree[idx] = tree[idx].comb (tree[idx * 2], tree[idx * 2 + 1]);
    }

    void typ2 (int idx, int l, int r, int L, int R) {
        if (L > r || R < l) return;
        if (L <= l && r <= R) {
            appf (tree[idx]);
            return;
        }
        push (idx, l, r);
        int mid = (l + r) / 2;
        typ2 (idx * 2, l, mid, L, R);
        typ2 (idx * 2 + 1, mid + 1, r, L, R);
        tree[idx] = tree[idx].comb (tree[idx * 2], tree[idx * 2 + 1]);
    }

    int typ3 (int idx, int l, int r, int L, int R) {
        if (L > r || R < l) return 0;
        if (L <= l && r <= R) {
            return std :: max (tree[idx].fupm, tree[idx].fdnm);
        }
        push (idx, l, r);
        int mid = (l + r) / 2;
        return std :: max (typ3 (idx * 2, l, mid, L, R), typ3 (idx * 2 + 1, mid + 1, r, L, R));
    }

    void solve () {
        int nn, q;
        std :: cin >> nn >> q;
        n = nn;
        tree.resize (4 * n);
        bld (1, 0, n - 1);
        
        for (int i = 0; i < q; i++) {
            int t;
            std :: cin >> t;
            
            if (t == 1) {
                int l, r, x;
                std :: cin >> l >> r >> x;
                l--; r--;
                typ1 (1, 0, n - 1, l, r, x);
            }
            else if (t == 2) {
                int l, r;
                std :: cin >> l >> r;
                l--; r--;
                typ2 (1, 0, n - 1, l, r);
            }
            else {
                int l, r;
                std :: cin >> l >> r;
                l--; r--;
                std :: cout << typ3 (1, 0, n - 1, l, r) << '\n';
            }
        }
    }
}

signed main () {
    std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
    // int TTT; std :: cin >> TTT; while (TTT --)
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/