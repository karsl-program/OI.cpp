#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        freopen("piano.in", "r", stdin);
        freopen("piano.out", "w", stdout);

        std :: ios :: sync_with_stdio(false);
        std :: cin.tie (0), std :: cout.tie (0);

        int n; std :: cin >> n;
        std :: vector<int> a(n);
        for (int i = 0; i < n; i ++) std :: cin >> a[i];

        if (n == 0) { std :: cout << "0\n0\n"; return; }
        if (n == 1) { std :: cout << "1\n0\n"; return; }

        std :: vector<int> s(n);
        for (int i = 1; i < n; i ++) {
            if (a[i] > a[i-1]) s[i] = s[i-1] + 1;
            else if (a[i] < a[i-1]) s[i] = s[i-1] - 1;
            else s[i] = s[i-1];
        }

        int bcnt = 0;
        for (int i = 1; i < n; i ++) {
            if (s[i] == 0 && a[i] == a[0]) bcnt++;
        }

        std :: unordered_map<int, int> cmap;
        for (int i = 1; i < n; i ++) {
            if (s[i] == 0) continue;
            int diff = a[i] - a[0];
            if (diff == 0) cmap[0]++;
            else {
                if ((diff > 0 && s[i] > 0) || (diff < 0 && s[i] < 0)) {
                    if (diff % s[i] == 0) {
                        int v = diff / s[i];
                        if (v >= 0) cmap[v] ++;
                    }
                }
            }
        }

        int tot0 = 1 + bcnt + cmap[0];
        int bcnt2 = tot0, bk = 0;

        for (const auto& e : cmap) {
            int k = e.first, cnt = e.second;
            if (k == 0) continue;
            int tv = 1 + bcnt + cnt;
            if (tv > bcnt2) { bcnt2 = tv; bk = k; }
            else if (tv == bcnt2) { if (k < bk) bk = k; }
        }

        std :: cout << bcnt2 << "\n" << bk << "\n";
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/