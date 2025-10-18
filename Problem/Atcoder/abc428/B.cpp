#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int N, K;
        std::string S;
        std::cin >> N >> K >> S;
        std::map<std::string, int> cnt;
        for (int i = 0; i <= N - K; ++i)
            ++cnt[S.substr(i, K)];
        int x = 0;
        for (auto &p : cnt) x = std::max(x, p.second);
        std::vector<std::string> res;
        for (auto &p : cnt)if (p.second == x) res.push_back(p.first);
        std::sort(res.begin(), res.end());
        std::cout << x << '\n';
        for (auto &s : res) std::cout << s << '\n';
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/