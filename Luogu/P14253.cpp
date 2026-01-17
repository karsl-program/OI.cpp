#include <bits/stdc++.h>

constexpr int N = 1e6 + 5;

int b[N], cnt[N], n, x, k[N];
struct A {
    int id, val;
} a[N];

bool cmp (A a, A b) { return a.val < b.val; }

namespace RunCode {
    void solve () {
        std :: cin >> n;
        for (int i = 1; i <= n; i ++) std :: cin >> x, b[i] = a[i].val = a[i - 1].val + x, a[i].id = i;
        std :: sort (a + 1, a + 1 + n, cmp);
        int lst = 0;
        int ans1 = 0;
        for (int i = 1; i <= n; i ++) {
            if (!b[i]) ans1 ++;
        }
        for (int i = 1; i <= n; i ++) {
            if (a[i].val == a[i - 1].val) k[a[i].id] = lst;
            else k[a[i].id] = ++ lst;
        } 
        // for (int i = 1; i <= n; i ++) std :: cout << a[i].val << ' ';
        // std :: cout << '\n';
        // for (int i = 1; i <= n; i ++) std :: cout << k[i] << ' ';
        // std :: cout << '\n';
        for (int i = 1; i <= n; i ++) {
            cnt[k[i]] ++;
        }
        int ans = 0;
        // if (a[1].val == 0) ans = cnt[1];
        for (int i = 1; i <= n; i ++) {
            cnt[k[i]] --;
            ans = std :: max (ans, cnt[k[i]]);
        }
        std :: cout << std :: max (ans, ans1) << '\n';
    }
}

int main () {
    std :: ios :: sync_with_stdio (false);
    std :: cin.tie (0), std :: cout.tie (0);
    int TTT; std :: cin >> TTT; while (TTT --)
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/