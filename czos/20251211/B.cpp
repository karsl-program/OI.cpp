#include <bits/stdc++.h>
constexpr int N = 3e5 + 5;
#define int long long
int a[N];
namespace RunCode {
    void solve () {
        std :: ios :: sync_with_stdio(false);
        std :: cin.tie (0);

        int n;
        std :: cin >> n;
        for (int i = 1; i <= n; i++) {
            std :: cin >> a[i];
        }

        std :: vector<int> left(n + 1, 0);
        std :: vector<int> rght(n + 1, n + 1);

        std :: stack<int> st;

        for (int i = 1; i <= n; i++) {
            while (!st.empty() && a[st.top()] < a[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n; i >= 1; i--) {
            while (!st.empty() && a[st.top()] < a[i]) {
                st.pop();
            }
            if (!st.empty()) {
                rght[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (left[i] != 0) {
                ans += (i - left[i] + 1);
            }
            if (rght[i] != n + 1) {
                ans += (rght[i] - i + 1);
            }
        }
        std :: cout << ans << std :: endl;
    }
}

signed main () {
    RunCode :: solve ();

    return 0;
}