#include <bits/stdc++.h>
#define int long long
namespace RunCode {
    void solve () {
        int n;
        std::cin >> n;
        
        std::vector<std::pair<int, int>> inter(n);
        for (int i = 0; i < n; i++) {
            std::cin >> inter[i].first >> inter[i].second;
        }
        
        int mx = LLONG_MIN, mn = LLONG_MAX;
        for (int x = inter[0].first; x <= inter[0].second; x++) {
            mx = std::max(mx, x);
            mn = std::min(mn, x);
        }
        
        for (int i = 1; i < n; i++) {
            int nxm = LLONG_MIN, nxn = LLONG_MAX;
            
            for (int x = inter[i].first; x <= inter[i].second; x++) {
                int c1 = mx * x;
                int c2 = mn * x;
                
                nxm = std::max(nxm, std::max(c1, c2));
                nxn = std::min(nxn, std::min(c1, c2));
            }
            
            mx = nxm;
            mn = nxn;
        }
        
        std::cout << mx << std::endl;
    }
}

signed main () {
    std :: ios :: sync_with_stdio(false);
    std :: cin.tie(0); std :: cout.tie(0);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/