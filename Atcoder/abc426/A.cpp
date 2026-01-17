#include <bits/stdc++.h>
using namespace std;
namespace RunCode {
    void solve () {
        map<string, int> vm;
        vm["Ocelot"] = 0;
        vm["Serval"] = 1;
        vm["Lynx"] = 2;
        
        string X, Y;
        cin >> X >> Y;
        
        if (vm[X] >= vm[Y]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
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