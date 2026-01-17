#include <bits/stdc++.h>
#define int long long
constexpr int N = 55;
int v[N];

namespace RunCode {
    void solve () {
        int n, a, b;
        std :: cin >> n >> a >> b;
        for (int i = 0; i < n; i ++) std :: cin >> v[i];

        std :: sort(v, v + n, std :: greater<int> ());

        int bnum = 0, bden = 1;
        for (int k = a; k <= b; k++) {
            int s = 0;
            for (int i = 0; i < k; i ++) s += v[i];
            if (s * bden > bnum * k) bnum = s, bden = k;
        }

        int x = v[b - 1];
        std :: vector<int> s;
        for (int i = 0; i < n; i ++) if (v[i] >= x) s.push_back(v[i]);
        int m = s.size();

        int n1 = m / 2, n2 = m - n1;
        std :: vector<int> s1, s2;
        for (int i = 0; i < n1; i ++) s1.push_back(s[i]);
        for (int i = n1; i < m; i ++) s2.push_back(s[i]);

        std :: vector<std :: unordered_map<int, int>> f1(n1 + 1);
        for (int msk = 0; msk < (1 << n1); msk ++) {
            int j = __builtin_popcount(msk);
            int sum = 0;
            for (int i = 0; i < n1; i ++)
                if (msk & (1 << i)) sum += s1[i];
            f1[j][sum] ++;
        }

        std :: vector<std :: unordered_map<int, int>> f2(n2 + 1);
        for (int msk = 0; msk < (1 << n2); msk ++) {
            int j = __builtin_popcount(msk);
            int sum = 0;
            for (int i = 0; i < n2; i ++) if (msk & (1 << i)) sum += s2[i];
            f2[j][sum] ++;
        }

        int ans = 0;
        for (int k = a; k <= b; k++) {
            if (bden == 0) continue;
            if ((k * bnum) % bden != 0) continue;
            int t = (k * bnum) / bden;

            int cnt = 0;
            int j1l = std :: max(0LL, k - n2), j1r = std :: min(k, n1);
            for (int j1 = j1l; j1 <= j1r; j1 ++) {
                int j2 = k - j1;
                if (j2 < 0 || j2 > n2) continue;
                for (auto &e : f1[j1]) {
                    int s1v = e.first, c1 = e.second;
                    int s2v = t - s1v;
                    if (f2[j2].count(s2v)) cnt += c1 * f2[j2][s2v];
                }
            }
            ans += cnt;
        }

        std :: cout << ans << std :: endl;
    }
}

signed main () {
    RunCode :: solve();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/