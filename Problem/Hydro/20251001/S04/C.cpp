#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M1 = 1e9 + 7,M2 = 1e9 + 9, B1 = 131, B2 = 131;

vector<int> p1(81, 1), p2(81, 1);

namespace RunCode {
    void pre() {
        for (int i = 1; i <= 80; i++) {
            p1[i] = (p1[i-1] * B1) % M1;
            p2[i] = (p2[i-1] * B2) % M2;
        }
    }

    pair<int, int> geth(const string &s) {
        int h1 = 0;
        int h2 = 0;
        for (char c : s) {
            h1 = (h1 * B1 + c) % M1;
            h2 = (h2 * B2 + c) % M2;
        }
        return {h1, h2};
    }

    void solve() {
        freopen("magic.in", "r", stdin);
        freopen("magic.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(0);

        pre();

        int n;
        cin >> n;
        vector<string> w;
        string t;
        for (int i = 0; i < n; i++) {
            cin >> t;
            w.push_back(t);
        }

        set<string> sa,sb;
        for (int i = 0; i < n; i++) {
            const string &s = w[i];
            for (int j = 0; j < s.size(); j++) {
                sa.insert(s.substr(0, j+1));
            }
            for (int j = 0; j < s.size(); j++) {
                sb.insert(s.substr(s.size() - j - 1, j+1));
            }
        }

        vector<string> da(sa.begin(), sa.end());
        vector<string> db(sb.begin(), sb.end());

        vector<pair<int, int>> ha;
        vector<int> la;
        for (const string &a : da) {
            auto h = geth(a);
            ha.push_back(h);
            la.push_back(a.size());
        }

        vector<pair<int, int>> hb;
        vector<int> lb;
        for (const string &b : db) {
            auto h = geth(b);
            hb.push_back(h);
            lb.push_back(b.size());
        }

        set<pair<int, int>> th;
        for (int i = 0; i < da.size(); i++) {
            int a1 = ha[i].first;
            int a2 = ha[i].second;
            int lai = la[i];
            for (int j = 0; j < db.size(); j++) {
                int lbj = lb[j];
                int b1 = hb[j].first;
                int b2 = hb[j].second;
                int h1 = (a1 * p1[lbj] % M1 + b1) % M1;
                int h2 = (a2 * p2[lbj] % M2 + b2) % M2;
                th.insert({h1, h2});
            }
        }

        cout << th.size() << endl;
    }

}

signed main() {
    RunCode::solve();
    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/