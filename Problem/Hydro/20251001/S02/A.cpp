#include <bits/stdc++.h>
std :: vector <int> a;
namespace RunCode {
    void solve () {
        freopen ("number.in", "r", stdin);
        freopen ("number.out", "w", stdout);

        std :: ios :: sync_with_stdio(false);
        std :: cin.tie(0);
        std :: cout.tie(0);

        int n;
        std :: cin >> n;
        a.resize(n + 1);
        for (int i = 0; i < n; i++) {
            std :: cin >> a[i];
        }

        int cnt = 0;
        std :: unordered_set<int> tn, nums;
        for (int i = 0; i < n; i ++) {
            if (i) {
                bool f = false;
                for (int x : nums) {
                    int tgt = a[i] - x;
                    if (tn.count(tgt)) {
                        f = true;
                        break;
                    }
                }

                if (!f && a[i] % 3 == 0 && nums.count(a[i] / 3)) {
                    f = true;
                }
                if (f) cnt ++;
            }

            for (int x : nums) {
                tn.insert(a[i] + x);
            }
            tn.insert(a[i] + a[i]);
            nums.insert(a[i]);
        }

        std :: cout << cnt;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/