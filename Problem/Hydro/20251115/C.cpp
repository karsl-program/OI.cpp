#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
a % b
a / b

gcd (a,b)

d = y - x g = gcd a, b

d/g m/g
*/
namespace RunCode {
    void solve () {
        int n, x, y;
        cin >> n >> x >> y;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int d = y - x, g = __gcd(x, d), _n = d / g, m = x / g;
        
        int r = a[0] % _n;
        for (int i = 1; i < n; i++) {
            if (a[i] % _n != r) {
                cout << -1 << endl;
                return;
            }
        }
        
        vector<int> q(n);
        for (int i = 0; i < n; i++) {
            q[i] = (a[i] - r) / _n;
        }
        
        int l = 0, rrr = 1e18;
        for (int i = 0; i < n; i++) {
            l = max(l, q[i] * m);
            rrr = min(rrr, q[i] * (m + _n) + r);
        }
        
        if (l > rrr) {
            cout << -1 << endl;
            return;
        }
        
        int k = rrr;
        int sum_q = 0;
        for (int i = 0; i < n; i++) {
            sum_q += q[i];
        }
        
        int res = n * k - m * sum_q;
        cout << res << endl;
    }
}

signed main () {
    ios :: sync_with_stdio(false);
    cin.tie (0);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/