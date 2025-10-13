#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::pair<int, int>> e(m);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--; v--;
            e[i] = {u, v};
        }
        int ans = m;
        for (int s = 0; s < (1 << n); ++s) {
            int c = 0;
            for (int i = 0; i < m; ++i) {
                int u = e[i].first;
                int v = e[i].second;
                if (((s >> u) & 1) != ((s >> v) & 1)) {
                    c++;
                }
            }
            ans = std::min(ans, m - c);
        }
        std::cout << ans << std::endl;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/