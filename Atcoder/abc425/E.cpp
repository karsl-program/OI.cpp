#include <bits/stdc++.h>

#define int long long

const int N = 5005;

std :: vector <int> pri;
std :: vector <std :: vector <int>> exp_t;
std :: vector <std :: vector <std :: pair <int, int>>> _f;

void gen_p(int n) {
    std :: vector<bool> is_p(n + 1, true);
    is_p[0] = is_p[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_p[i]) {
            pri.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                is_p[j] = false;
            }
        }
    }
}

void pre_f() {
    int p_c = pri.size();
    exp_t.resize(p_c, std :: vector<int>(N + 1, 0));
    
    for (int i = 0; i < p_c; i++) {
        int p = pri[i];
        for (int j = 1; j <= N; j++) {
            int cnt = 0;
            int tmp = j;
            while (tmp % p == 0) {
                cnt++;
                tmp /= p;
            }
            exp_t[i][j] = exp_t[i][j - 1] + cnt;
        }
    }
    
    _f.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < p_c; j++) {
            if (pri[j] > i) break;
            int exp = exp_t[j][i];
            if (exp > 0) {
                _f[i].emplace_back(j, exp);
            }
        }
    }
}

int pw(int b, int e, int m) {
    int r = 1;
    b %= m;
    while (e > 0) {
        if (e & 1) {
            r = (r * b) % m;
        }
        b = (b * b) % m;
        e >>= 1;
    }
    return r;
}

namespace RunCode {
    void solve () {
        std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
        gen_p(N);
        pre_f();

        int t, m;
        std :: cin >> t >> m;
        while (t --) {
            int n; std :: cin >> n;
            std :: vector <int> c(n);
            int l = 0;
            for (int i = 0; i < n; i++) {
                std :: cin >> c[i];
                l += c[i];
            }
            
            std :: vector<int> de(pri.size(), 0);
            for (int i = 0; i < n; i++) {
                for (auto [p_i, e] : _f[c[i]]) {
                    de[p_i] += e;
                }
            }

            int res = 1;
            for (int i = 0; i < pri.size(); i++) {
                if (pri[i] > l) break;
                int num_e = exp_t[i][l];
                int d_e = num_e - de[i];
                
                if (d_e > 0) {
                    res = (res * pw(pri[i], d_e, m)) % m;
                }
            }
            
            std :: cout << res << '\n';
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