#include <bits/stdc++.h>
using namespace std;

namespace RunCode {
    string rep (int);

    string to_string(int x) {
        if (x == 0) {
            return "0";
        }
        int tx = x;
        vector<int> b;
        while (tx > 0) {
            b.push_back(tx & 1);
            tx >>= 1;
        }
        vector<string> t;
        for (int i = b.size() - 1; i >= 0; i--) {
            if (b[i] == 1) {
                t.push_back(rep(i));
            }
        }
        string r = "";
        for (int i = 0; i < t.size(); i++) {
            if (i > 0) {
                r += "+";
            }
            r += t[i];
        }
        return r;
    }

    string rep(int k) {
        if (k == 0) {
            return "2(0)";
        } else if (k == 1) {
            return "2";
        } else {
            return "2(" + to_string(k) + ")";
        }
    }

    void solve() {
        freopen("pow.in", "r", stdin);
        freopen("pow.out", "w", stdout);
        string s;
        cin >> s;
        vector<int> e;
        int p = 0;
        while (s != "0") {
            int ld = s[s.size() - 1] - '0';
            if (ld % 2 == 1) {
                e.push_back(p);
            }
            string q = "";
            int c = 0;
            for (int i = 0; i < s.size(); i++) {
                int d = s[i] - '0';
                int n = c * 10 + d;
                int qi = n / 2;
                c = n % 2;
                if (q.empty() && qi == 0) {
                    continue;
                }
                q += ('0' + qi);
            }
            if (q.empty()) {
                q = "0";
            }
            s = q;
            p++;
        }
        vector<string> t;
        for (int i = e.size() - 1; i >= 0; i--) {
            t.push_back(rep(e[i]));
        }
        string a = "";
        for (int i = 0; i < t.size(); i++) {
            if (i > 0) {
                a += "+";
            }
            a += t[i];
        }
        cout << a << endl;
    }
}

int main() {
    RunCode::solve();
    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/