#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, p[N][3], use[3];
pair <int, int> l[N];

int kma (int x, int y, int z) {
	if (x >= y && x >= z) return 0;
	if (y >= x && y >= z) return 1;
	if (z >= x && z >= y) return 2;
	return 1;
}

void solve () {
	use[0] = use[1] = use[2] = 0;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 3; j ++) {
			cin >> p[i][j];
		}
		int h = kma(p[i][0], p[i][1], p[i][2]);
		l[i].first = p[i][h];
		l[i].second = h;
		int ma = 0;
		for (int j = 0; j < 3; j ++) {
			if (j == h) continue;
			ma = max (ma, p[i][j]);
		}
		l[i].first -= ma;
	}
	for (int i = 1; i <= n; i ++) {
		int cur = kma (p[i][0], p[i][1], p[i][2]);
		use[cur] ++;
		ans += p[i][cur];
	}
	int t = -1;
	if (use[0] > n / 2) t = 0;
	else if (use[1] > n / 2) t = 1;
	else if (use[2] > n / 2) t = 2;
	if (t == -1) {
		cout << ans << endl; return ;
	} else {
		sort (l + 1, l + n + 1);
		int k = use[t] - n / 2;
		for (int i = 1, p = 1; p <= k; i ++) {
			if (l[i].second == t) ans -= l[i].first, p ++;
		}
		cout << ans << endl;
	}
}

signed main () {
//	freopen ("club2.in", "r", stdin);
//	freopen ("club.out", "w", stdout);
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int t; cin >> t; while (t --)
	solve ();
	
	return 0;
}