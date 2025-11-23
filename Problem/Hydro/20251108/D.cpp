#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace RunCode {
    const int MOD = 998244353;
    
    int qpow(int a, int b, int mod) {
        int res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    
    void solve() {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;
            for (int k = i; k < j; k++) {
                cnt[k] = j - i;
            }
            i = j - 1;
        }
        
        int ans = 1;
        int l = 0;
        for (int i = 0; i < n; i++) {
            while (l < i && a[i] - a[l] > d) {
                l++;
            }
            ans = (ans * (i - l + 1)) % MOD;
            ans = (ans * qpow(cnt[i], MOD - 2, MOD)) % MOD;
        }
        
        cout << ans << endl;
    }
}

int main() {
    RunCode::solve();
    return 0;
}

/*
Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth
*/