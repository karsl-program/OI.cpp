#include <bits/stdc++.h>

namespace RunCode {
    std :: string _to (int p1, int p2) {  // p1 m p2 d
        std :: string res;
        if (p1 < 10) res += '0', res += p1 + 48;
        else res += p1 / 10 + 48, res += p1 % 10 + 48;
        res += '-';
        if (p2 < 10) res += '0', res += p2 + 48;
        else res += p2 / 10 + 48, res += p2 % 10 + 48;
        return res;
    }

    void solve () {
        std :: vector <std :: string> s;
        int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i <= 12; i ++) {
            for (int j = 1; j <= m[i]; j ++) {
                s.push_back (_to (i, j));
            }
        }
        std :: string k;
        std :: cin >> k;
        int ans = 1e9;
        for (std :: string _ : s) {
            int cnt = 0;
            for (int i = 0; i < _.size (); i ++) {
                if (_[i] != k[i]) cnt ++;
            }
            ans = std :: min (cnt, ans);
        }
        std :: cout << ans;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/