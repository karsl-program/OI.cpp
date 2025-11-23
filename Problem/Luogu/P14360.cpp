#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005, MOD = 998244353;
int dp[N], n, res = 1, cnt, a[N], sum;

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    dp[0] = 1;
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++) {
        sum = 0;
        for (int j = 0; j <= a[i]; j ++) {
            sum += dp[j];
            sum %= MOD;
        }
        for (int j = 5001; j >= a[i]; j --) {
            dp[j] += dp[j - a[i]];
            dp[j] %= MOD;
        }
        cnt += res - sum; cnt %= MOD;
        res <<= 1; res %= MOD;
    }
    cout << (cnt + MOD) % MOD;
}

signed main () {
//  freopen("polygon3.in", "r", stdin);
//  freopen("polygon.out", "w", stdout);
    solve ();
    
    return 0;
}