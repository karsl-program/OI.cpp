#include <bits/stdc++.h>
using namespace std;

string s;
int cnt, pos1, pos2;
namespace RunCode {
    void solve () {
        cin >> s >> s;
        int posC;
        for (int i = 0; i < s.size (); i ++) {
            if (s [i] == 'C') {
                posC = i;
                break;
            }
        }
        pos1 = s.size () - 1;
        for (int i = posC; i < s.size (); i ++) {
            if (s[i] == 'X') { pos1 = i; break; }
        }
        for (int i = posC; ~i; i --) {
            if (s[i] == 'X') { pos2 = i; break; }
        }
        for (int i = pos2; i <= pos1; i ++) {
            if (s[i] == 'h') cnt ++;
        }
        cout << cnt;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/