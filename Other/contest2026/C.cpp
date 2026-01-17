#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace RunCode {
    void solve () {
        int n;
        cin >> n;
        
        map<int, vector<int>> grp;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            grp[b].push_back(a);
        }
        
        vector<array<int, 2>> seg;
        for (auto &[b, vec] : grp) {
            sort(vec.begin(), vec.end());
            int L = vec.front();
            int R = vec.back();
            seg.push_back({L, R});
        }
        
        int m = seg.size();
        int dpL = 0, dpR = 0;
        
        int l0 = seg[0][0], r0 = seg[0][1];
        int len0 = r0 - l0;
        
        dpL = min(abs(0 - l0) + 2 * len0, abs(0 - r0) + len0);
        dpR = min(abs(0 - r0) + 2 * len0, abs(0 - l0) + len0);
        
        for (int i = 1; i < m; ++i) {
            int L = seg[i][0], R = seg[i][1];
            int len = R - L;
            int pL = seg[i - 1][0], pR = seg[i - 1][1];
            
            int cLL = min(abs(pL - L) + 2 * len, abs(pL - R) + len);
            int cLR = min(abs(pL - R) + 2 * len, abs(pL - L) + len);
            int cRL = min(abs(pR - L) + 2 * len, abs(pR - R) + len);
            int cRR = min(abs(pR - R) + 2 * len, abs(pR - L) + len);
            
            int ndpL = min(dpL + cLL, dpR + cRL);
            int ndpR = min(dpL + cLR, dpR + cRR);
            
            dpL = ndpL;
            dpR = ndpR;
        }
        
        int lstL = seg[m - 1][0], lstR = seg[m - 1][1];
        int ans = min(dpL + abs(lstL - 0), dpR + abs(lstR - 0));
        
        cout << ans << endl;
    }
}

signed main() {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/