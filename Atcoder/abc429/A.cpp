#include <bits/stdc++.h>
using namespace std;
namespace RunCode {
    void solve () {
        int n, m;
        cin >> n >> m;
        
        for (int i = 1; i <= n; i++) {
            if (i <= m) {
                cout << "OK" << endl;
            } else {
                cout << "Too Many Requests" << endl;
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