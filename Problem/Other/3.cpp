#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

int a[N], n, q, b[N], lst[N], ans[N];

int tree[N << 2];

void pushup (int u) {
	tree[u] = max (tree[u << 1], tree[u << 1 | 1]);
}

void update (int pos, int l, int r, int q, int k) {
	if (l == r && l == q) { tree[pos] = max (tree[pos], k); return ; }
	int mid = (l + r) >> 1;
	if (q <= mid) update (pos << 1, l, mid, q, k);
	if (q > mid) update (pos << 1 | 1, mid + 1, r, q, k);
	pushup (pos);
}

int query (int pos, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {return tree[pos];}
	int mid = (l + r) >> 1, res = 0;
	if (ql <= mid) res = max (res, query (pos << 1, l, mid, ql, qr));
	if (qr > mid) res = max (res, query (pos << 1 | 1, mid + 1, r, ql, qr));
	return res;
}

struct block {
	int l, r, id;
} B[N];

bool cmp (block a, block b) { return a.r < b.r; }

vector <int> g[N];

void init () {
	for (int i = 1; i <= n; i ++) {
		int k = sqrt (a[i]);
		for (int j = 1; j <= k; j ++) {
			if (a[i] % j == 0) {g[i].push_back (j); if (j != a[i] / j) g[i].push_back (a[i] / j);}
		}
	}
}

void solve () {
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> a[i], b[i] = a[i];
	init ();
	for (int i = 1; i <= q; i ++) {
		int l, r; cin >> l >> r;
		B[i].l = l, B[i].r = r, B[i].id = i;
	}
	sort (B + 1, B + 1 + q, cmp);
	for (int i = 1, r = 1; i <= n && r <= q; i ++) {
		for (int k : g[i]) {
			if (lst[k]) update (1, 1, n, lst[k], k);
			lst[k] = i;
		}
		for (; r <= q && B[r].r == i; r ++) ans[B[r].id] = query (1, 1, n, B[r].l, B[r].r);
	}
	for (int i = 1; i <= q; i ++) cout << ans[i] << endl;
}

signed main () {
	freopen ("fac.in", "r", stdin);
	freopen ("fac.out", "w", stdout);
	solve ();
	
	return 0;
}