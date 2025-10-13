#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace RunCode {
    int f(int n) {
        if (n % 2 == 0) return 2;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return i;
        }
        return n;
    }

    map<int, int> g(int m) {
        map<int, int> fac;
        while (m % 2 == 0) {
            fac[2]++;
            m /= 2;
        }
        for (int i = 3; i * i <= m; i += 2) {
            while (m % i == 0) {
                fac[i]++;
                m /= i;
            }
        }
        if (m > 1) fac[m]++;
        return fac;
    }

    void solve() {
        freopen("fun.in", "r", stdin);
        freopen("fun.out", "w", stdout);

        int n;
        cin >> n;

        int p = f(n);
        int q = n / p;

        int m = (p - 1) * (q - 1);

        map<int, int> fac = g(m);

        int cnt = 1;
        for (auto &f : fac) {
            cnt *= (f.second + 1);
        }

        int sum = 1;
        for (auto &f : fac) {
            int pr = f.first;
            int ex = f.second;
            int s = 1;
            int pw = 1;
            for (int i = 0; i < ex; i++) {
                pw *= pr;
                s += pw;
            }
            sum *= s;
        }

        cout << cnt << "\n";
        cout << sum << "\n";
    }
}

signed main() {
    RunCode::solve();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/