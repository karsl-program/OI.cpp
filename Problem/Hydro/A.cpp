#include <bits/stdc++.h>
#define int long long
const int N = 5e5 + 5;

int n, k, d;
int h[N];

std :: pair <bool, int> check (int x) {
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        int j = i, minn = h[i], maxx = h[i];
        while (j <= n && maxx - minn <= x) j ++, maxx = std :: max (maxx, h[j]), minn = std :: min (minn, h[j]);
        // if (j == i) return {false, -1};
        if (j > n) { ++ cnt; break; }
        i = j - 1;
        ++ cnt;
    }
    return {cnt <= k, cnt};
}

void binary () {
    int l = 0, r = 1e9, mid, ans;
    while (l < r) {
        mid = l + r >> 1;
        if (check (mid).first) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    std :: cout << ans << std :: endl;
}

int ST_ma[N][21], ST_mi[N][21];

void init () {
    for (int i = 1; i <= n; i ++) ST_ma[i][0] = h[i], ST_mi[i][0] = h[i];
    for (int j = 1; j <= 20; j ++)
        for (int i = 1; i + (1 << j) - 1 <= n; i ++) {
            ST_ma[i][j] = std :: max (ST_ma[i][j - 1], ST_ma[i + (1 << (j - 1))][j - 1]);
            ST_mi[i][j] = std :: min (ST_mi[i][j - 1], ST_mi[i + (1 << (j - 1))][j - 1]);
        }
}

int dp[N], lg[N];
std :: pair <int, int> K[N];

int qry (int x, int y) {
    // return h[x] ~ h[y] max - min
    int len = y - x + 1;
    int j = lg[len];
    return std :: max (ST_ma[x][j], ST_ma[y - (1 << j) + 1][j]) - std :: min (ST_mi[x][j], ST_mi[y - (1 << j) + 1][j]);
}

int _binary (int i) {
    int l = i, r = n, mid, ans = n;
    while (l <= r) {
        mid = l + r >> 1;
        if (qry (i, mid) <= d) ans = mid, l = mid + 1;
        else r = mid - 1;
        // std :: cout << i << ':' << mid << ':' << ans << ':' << qry (i, mid) << std :: endl;
    }
    return ans;
}

void SOLVE () {
    lg[1] = 0;
    for (int i = 2; i <= n; i ++) lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; i ++) {
        K[i] = std :: make_pair (_binary (i), i);
        // std :: cout << i << ':' << _binary (i) << std :: endl;
    }
    std :: sort (K + 1, K + n + 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = K[i - 1].first + 1; j <= K[i].first; j ++) dp[j] = dp[j - 1];
        dp[K[i].first] = std :: max (dp[K[i].first], dp[K[i].second - 1] + K[i].first - K[i].second + 1);
        // std :: cout << K[i].second << ',' << K[i].first << ':' << dp[K[i].first] << std :: endl;
    }
    std :: cout << dp[n] << std :: endl;
}

namespace RunCode {
    void solve () {
        freopen ("photo.in", "r", stdin);
        freopen ("photo.out", "w", stdout);
        std :: cin >> n >> k >> d;
        for (int i = 1; i <= n; i ++) std :: cin >> h[i];
        binary ();
        std :: cout << check (d).second << std :: endl;
        init ();
        SOLVE ();
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/