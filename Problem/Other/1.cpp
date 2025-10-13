#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int N = 500005;

int a[N], n, pre[N], ans, x1;

void solve () {
    ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
	int p = pre[n] / 3;
    if (pre[n] % 3 != 0) {
        cout << 0;
        return;
    }
    for (int i = 1; i <= n; i ++) {
		if (p == pre[i]) x1 ++;
		if (2 * p == pre[i]) ans += x1;
	}
    cout << ans;
}

signed main () {
    solve ();

    return 0;
}