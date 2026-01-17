#include <bits/stdc++.h>
#define int long long

std :: vector<int> arr;

int count (int x) {
    if (x < 1) return 0;
    auto it = std :: upper_bound (arr.begin(), arr.end(), x);
    int ca = std :: distance (arr.begin(), it);
    return x - ca;
}

namespace RunCode {
    void solve () {
        std :: ios :: sync_with_stdio(false);
        std :: cin.tie(nullptr), std :: cout.tie(nullptr);

        int n, q;
        std :: cin >> n >> q;
        arr.resize (n);
        for (int i = 0; i < n; i ++) {
            std :: cin >> arr[i];
        }

        std :: sort(arr.begin(), arr.end());

        while (q --) {
            int x, y;
            std :: cin >> x >> y;

            int b = count (x - 1);
            int t = b + y;

            int l = x;
            int r = x + y + n;

            while (l < r) {
                int mid = l + r >> 1;
                if (count (mid) >= t) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

            std :: cout << l << '\n';
        }
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/