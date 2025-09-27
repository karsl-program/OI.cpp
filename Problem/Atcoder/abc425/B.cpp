#include <bits/stdc++.h>
int a[15], cnt[15];
std :: vector <int> p;
namespace RunCode {
    void solve () {
        int n;
        std :: cin >> n;
        for (int i = 1; i <= n; i ++) {std :: cin >> a[i]; if (a[i] > 0) cnt[a[i]] ++;}
        for (int i = 1; i <= n; i ++) {
            if (cnt[i] > 1) return (void)(std ::cout << "No");
            else {
                if (cnt[i] != 1) p.push_back(i);
            }
        }
        std :: cout << "Yes\n";
        for (int i = 1; i <= n; i ++) {
            if (a[i] == -1) std :: cout << p.back() << ' ', p.pop_back();
            else std :: cout << a[i] << ' ';
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