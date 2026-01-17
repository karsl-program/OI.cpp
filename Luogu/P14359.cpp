#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
constexpr int N = 5e5 + 5, V = 2e6 + 5;

int dp[N], a[N], n, k, pre[N], cnt[V];
vector <pii> ans;

bool cmp (pii a, pii b) {
    return a.se < b.se;
}

namespace RunCode {
    void solve () {
        cin >> n >> k;
        for (int i = 1; i <= n; i ++) cin >> a[i], pre[i] = pre[i - 1] ^ a[i];
        for (int i = 1; i <= V; i ++) cnt[i] = -1;
        for (int i = 1; i <= n; i ++) {
            if (cnt[pre[i] ^ k] != -1) {
                ans.push_back ({cnt[pre[i] ^ k] + 1, i});
            }
            cnt[pre[i]] = i;
        }
        sort (ans.begin (), ans.end (), cmp);
        for (int i = 0; i < ans.size (); i ++) {
            if (ans[i].se != ans[i - 1].se) {
                for (int j = ans[i - 1].se + 1; j <= ans[i].se; j ++) dp[j] = dp[j - 1];
            }
            dp[ans[i].se] = max (dp[ans[i].se], dp[ans[i].fi - 1] + 1);
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++) ans = max (ans, dp[i]);
        cout << ans << '\n';
    }
}

int main () {
    ios :: sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/