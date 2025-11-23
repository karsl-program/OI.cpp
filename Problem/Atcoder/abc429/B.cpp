#include <bits/stdc++.h>

namespace RunCode {
    void solve () {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            sum += a[i];
        }
        
        for (int i = 0; i < n; i++) {
            if (sum - a[i] == m) {
                std::cout << "Yes" << std::endl;
                return;
            }
        }
        std::cout << "No" << std::endl;
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/