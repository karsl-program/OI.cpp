#include <bits/stdc++.h>
using namespace std;
namespace RunCode {
    void solve () {
        string s;
        cin >> s;
        
        unordered_map<char, int> count;
        
        for (char c : s) {
            count[c]++;
        }
        
        for (char c : s) {
            if (count[c] == 1) {
                cout << c << endl;
                break;
            }
        }
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/