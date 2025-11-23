#include <bits/stdc++.h>
#define int long long
constexpr int N = 1e5 + 5;
int n, m, a[N];

namespace RunCode {
    bool check (int x) {
        int cnt = 0;
        for (int i = 1; i <= n; i ++) {
            int j = i;
            while (j <= n && a[j] - a[i - 1] <= x) j ++;
            // std :: cout << x << ':' << cnt << ' ' << i << ' ' << j << std :: endl;
            cnt ++;
            if (j == i) return false;
            if (j > n) break;
            i = j - 1;
        }
        return cnt <= m;
    }

    void solve () {
        std :: cin >> n >> m;
        for (int i = 1; i <= n; i ++) std :: cin >> a[i], a[i] += a[i - 1];
        int l = 0, r = 1e9, mid, ans;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check (mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        std :: cout << ans;
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/