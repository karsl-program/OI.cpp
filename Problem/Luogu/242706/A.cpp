#include <bits/stdc++.h>
using namespace std;

#define int long long

namespace RunCode {
    const int MAXN = 2e5 + 5;
    
    void solve () {
        int n, m, k, l, r;
        cin >> n >> m >> k >> l >> r;
        
        int sc[MAXN];
        for (int i = 0; i <= n; i++) {
            sc[i] = 0;
        }
        
        for (int i = 0; i < k; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            
            if (v <= l) {
                sc[x] += 100;
            } else if (v >= r) {
                sc[x] += 0;
            } else {
                sc[x] += v;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            cout << sc[i];
            if (i < n) cout << " ";
        }
        cout << endl;
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/