#include <bits/stdc++.h>
#define int long long
const int INF = 1e18;
namespace RunCode {
    void solve () {
        int n, k;
        std :: cin >> n >> k;
        std :: vector<int> t(n);
        for (int i = 0; i < n; i++) {
            std :: cin >> t[i];
        }

        std :: vector<std :: string> mat(k);
        for (int i = 0; i < k; i++) {
            std :: cin >> mat[i];
        }

        std :: vector<std :: set<int>> sets(k);
        for (int i = 0; i < n; i++) {
            int tidx = t[i] - 1;
            sets[tidx].insert(i + 1);
        }

        std :: vector<int> dp(n + 1, INF);
        std :: vector<bool> vis(n + 1, false);
        std :: priority_queue<std :: pair<int, int>, std :: vector<std :: pair<int, int>>, std :: greater<std :: pair<int, int>>> pq;

        dp[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;

            if (u == n) {
                break;
            }

            int tu = t[u - 1];
            if (sets[tu - 1].find(u) != sets[tu - 1].end()) {
                sets[tu - 1].erase(u);
            }

            for (int x = 1; x <= k; x++) {
                if (mat[tu - 1][x - 1] != '1') {
                    continue;
                }

                auto& s = sets[x - 1];
                if (s.empty()) {
                    continue;
                }

                auto it = s.lower_bound(u);
                if (it != s.end()) {
                    int v = *it;
                    int nd = d + std :: abs(u - v);
                    if (nd < dp[v]) {
                        dp[v] = nd;
                        pq.push({nd, v});
                    }
                }
                if (it != s.begin()) {
                    it--;
                    int v = *it;
                    int nd = d + std :: abs(u - v);
                    if (nd < dp[v]) {
                        dp[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }
        }

        if (dp[n] >= INF) {
            std :: cout << -1 << '\n';
        } else {
            std :: cout << dp[n] << '\n';
        }
    }
}

signed main () {
    std :: ios :: sync_with_stdio(false);
    std :: cin.tie (0);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/