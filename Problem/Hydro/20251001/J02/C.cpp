#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace RunCode {
    void solve() {
        freopen("collect.in", "r", stdin);
        freopen("collect.out", "w", stdout);
        int n;
        cin >> n;
        vector<pair<int, int>> p(n);
        
        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
        }
        
        sort(p.begin(), p.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        });
        
        int c = 0;
        int my = -2e9;
        
        for (const auto& pt : p) {
            if (pt.second >= my) {
                c++;
                my = pt.second;
            }
        }
        
        cout << c << endl;
    }
}

signed main() {
    RunCode::solve();
    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/