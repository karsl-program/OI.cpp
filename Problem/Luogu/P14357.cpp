#include <bits/stdc++.h>
using namespace std;
namespace RunCode {
    bool cmp (char a, char b) {
        return a > b;
    }

    void solve () {
        string s, s1;
        cin >> s;
        for (int i = 0; i < s.size (); i ++) {
            if (s[i] >= '0' && s[i] <= '9') s1 += s[i];
        }
        sort(s1.begin (), s1.end (), cmp);
        cout << s1 << '\n';
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/