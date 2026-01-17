#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace RunCode {
    void solve() {
        freopen("colorful.in", "r", stdin);
        freopen("colorful.out", "w", stdout);

        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<int> all;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                all.push_back(a[i][j]);
            }
        }

        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        int tot = all.size();
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = lower_bound(all.begin(), all.end(), a[i][j]) - all.begin();
            }
        }

        int tot_rec = 1LL * n * (n + 1) / 2 * m * (m + 1) / 2;
        vector<int> cnt(tot, 0);
        vector<bool> in_rec(tot, false);
        vector<int> rec;
        int same = 0;

        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = r1; r2 < n; r2++) {
                rec.clear();
                for (int j = 0; j < m; j++) {
                    if (b[r1][j] != b[r2][j]) 
                        continue;
                    int c = b[r1][j];
                    cnt[c]++;
                    if (!in_rec[c]) {
                        in_rec[c] = true;
                        rec.push_back(c);
                    }
                }
                for (int c : rec) {
                    int k = cnt[c];
                    same += k * (k + 1) / 2;
                    cnt[c] = 0;
                    in_rec[c] = false;
                }
            }
        }

        int ans = tot_rec - same;
        cout << ans << endl;
    }
}

signed main() {
    RunCode::solve();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/