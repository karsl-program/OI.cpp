#include <bits/stdc++.h>
const int N = 1e5 + 5;
int a[N], pre[N], s[N], ans = 1e9;
namespace RunCode {
    void solve () {
        int n;
        std :: cin >> n;
        for (int i = 1; i <= n; i ++) {
            std :: cin >> a[i], pre[i] = pre[i - 1] + a[i];
        }
        for (int i = n; i >= 1; i --) s[i] = s[i + 1] + a[i];
        // for (int i = 1; i <= n; i ++) std :: cout << pre[i] << " ";
        // for (int i = n; i >= 1; i --) std :: cout << s[i] << " ";
        for (int i = 0; i <= n; i ++) {
            ans = std :: min (ans, pre[i] - i + (n - i) * 2 - s[i + 1]);
        }
        std :: cout << ans;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/