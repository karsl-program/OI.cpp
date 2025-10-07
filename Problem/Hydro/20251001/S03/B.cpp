#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
namespace RunCode {
    int qpow(int b, int e, int m) {
        if (e < 0) return 0;
        int r = 1;
        b %= m;
        while (e) {
            if (e & 1) r = (r * b) % m;
            b = (b * b) % m;
            e >>= 1;
        }
        return r;
    }

    void solve() {
        freopen ("travel.in", "r", stdin);
        freopen ("travel.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, m, s, t;
        cin >> n >> m >> s >> t;

        vector<int> p;
        p.push_back(s);
        p.push_back(t + 1);

        vector<pair<int, int>> seg;
        for (int i = 0; i < m; i++) {
            int x, l, r;
            cin >> x >> l >> r;
            seg.push_back(make_pair(l, r));
            p.push_back(l);
            p.push_back(r + 1);
        }

        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());

        vector<int> c(p.size(), 0);

        for (int i = 0; i < m; i++) {
            int l = seg[i].first;
            int r = seg[i].second;
            int pos1 = lower_bound(p.begin(), p.end(), l) - p.begin();
            c[pos1]--;
            int re = r + 1;
            int pos2 = lower_bound(p.begin(), p.end(), re) - p.begin();
            if (pos2 < p.size()) {
                c[pos2]++;
            }
        }

        int cur = n;
        int tot = 0;

        int cnt = p.size();
        int st = -1;
        for (int i = 0; i < cnt; i++) {
            if (p[i] == s) {
                st = i;
                break;
            }
        }

        if (st == -1) {
            cout << 0 << endl;
            return;
        }

        cur += c[st];
        if (cur < 0) cur = 0;
        tot = cur % mod;

        if (tot < 0) tot = 0;

        for (int i = st; i < cnt - 1; i++) {
            if (p[i] > t) break;

            int len = p[i + 1] - p[i];

            if (len > 1) {
                tot = tot * qpow(cur, len - 1, mod) % mod;
            }

            if (i == cnt - 2) {
                break;
            }

            cur += c[i + 1];
            if (cur < 0) cur = 0;

            tot = tot * cur % mod;
        }

        cout << tot << endl;
    }
}

signed main() {
    RunCode::solve();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/