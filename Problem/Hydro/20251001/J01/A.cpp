#include <bits/stdc++.h>
#define int long long

bool check (int x) {
    std :: string s = std :: to_string(x);
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l ++;
        r --;
    }
    return true;
}

namespace RunCode {
    void solve () {
        int n;
        std :: cin >> n;
        
        int ans = 0;
        
        for (int i = 1; i <= 1000000; i++) {
            int c = i * i * i;
            if (c > n) {
                break;
            }
            if (check (c)) {
                ans = c;
            }
        }
        
        std :: cout << ans;
    }
}

signed main () {
    freopen("abba.in", "r", stdin);
    freopen("abba.out", "w", stdout);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/