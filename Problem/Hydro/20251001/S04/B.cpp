#include <bits/stdc++.h>
using namespace std;
const int N = 3000, M = 6000;
struct Nd {
    int l, p, nx[26];
} nd[M];

int sz, la, f[N][N];
namespace RunCode {
    void ini() {
        nd[0].l = 0;
        nd[0].p = -1;
        for (int i = 0; i < 26; i++) nd[0].nx[i] = -1;
        sz = 1;
        la = 0;
    }

    void add(int c, int &t) {
        int u = sz++;
        nd[u].l = nd[la].l + 1;
        nd[u].p = -1;
        for (int i = 0; i < 26; i++) nd[u].nx[i] = -1;

        int v = la;
        while (v != -1 && nd[v].nx[c] == -1) {
            nd[v].nx[c] = u;
            v = nd[v].p;
        }

        if (v == -1) {
            nd[u].p = 0;
        } else {
            int w = nd[v].nx[c];
            if (nd[w].l == nd[v].l + 1) {
                nd[u].p = w;
            } else {
                int cl = sz++;
                nd[cl].l = nd[v].l + 1;
                nd[cl].p = nd[w].p;
                for (int i = 0; i < 26; i++) nd[cl].nx[i] = nd[w].nx[i];
                nd[w].p = cl;
                nd[u].p = cl;
                while (v != -1 && nd[v].nx[c] == w) {
                    nd[v].nx[c] = cl;
                    v = nd[v].p;
                }
            }
        }
        la = u;
        t += nd[u].l - nd[nd[u].p].l;
    }

    void solve() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        freopen("substring.in", "r", stdin);
        freopen("substring.out", "w", stdout);

        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        for (int l = 0; l < n; l++) {
            ini();
            int t = 0;
            for (int r = l; r < n; r++) {
                int c = s[r] - 'a';
                add(c, t);
                f[l][r] = t;
            }
        }

        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << f[l][r] << '\n';
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