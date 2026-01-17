#include <bits/stdc++.h>
using namespace std;
namespace RunCode {
    void solve () {
        int n;
        cin >> n;
        while (n --) {
            string s;
            int m, k;
            cin >> k >> m;
            for (int i = 0; i < m; i ++) {
                for (int j = 0; j < k / m; j ++) s += ('a' + i);
            }
            while (s.size () < k) s += 'a';
            cout << s << '\n';
        }
    }
}

int main () {
    ios :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/