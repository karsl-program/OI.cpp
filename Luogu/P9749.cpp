#include <bits/stdc++.h>
#define int long long
const int N = 1e5 + 5;
int v[N], a[N], pre[N];
namespace RunCode {
    void solve () {
        int n, d;
        std :: cin >> n >> d;
        for (int i = 2; i <= n; i ++) {
            std :: cin >> v[i];
            pre[i] = pre[i - 1] + v[i];
        }
        for (int i = 1; i <= n; i ++) std :: cin >> a[i];
        int start = 1, ans = 0, k = 0;
        for (int i = 1; i < n; ) {
            int j = i + 1;
            while (j < n && a[j] >= a[i]) j ++;
            // if (j > n) j = n;
            // std :: cout << j << " " << pre[j] << " " << i << " " << pre[i] << std :: endl;
            int p = pre[j] - pre[i];
            ans += (p - k + d - 1) / d * a[i];
            k += (p - k + d - 1) / d * d - p;
            i = j;
            // std :: cout << ans << std :: endl;
        }
        std :: cout << ans << std :: endl;
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/