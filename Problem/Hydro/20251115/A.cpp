#include <bits/stdc++.h>
#define int long long
#define gcd std :: __gcd
constexpr int N = 5e5 + 10, M = 1e6 + 5;
int n, m;

void print (int x) {
    if (x > 9) print (x / 10);
    putchar (x % 10 + '0');
}

int read () {
    int x = 0, f = 1; char ch = getchar ();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar (); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar (); }
    return x * f;
}

struct Func {
    int p, q;

    void re () {
        int k = gcd (p, q);
        p /= k, q /= k;
    }

    Func (int p, int q) : p (p), q (q) { re (); }

    Func (int k) : p (k), q (1) {};

    Func () : p (0), q (1) {};

    bool operator == (const Func &o) const {
        return p == o.p && q == o.q;
    } 
    
    bool operator < (const Func &o) const {
        return p * o.q < q * o.p;
    }
    
    bool operator > (const Func &o) const {
        return p * o.q > q * o.p;
    }

    bool operator <= (const Func &o) const {
        return p * o.q <= q * o.p;
    } 
    
    bool operator >= (const Func &o) const {
        return p * o.q >= q * o.p;
    }

    Func operator * (const Func &o) const {
        Func res = Func (p * o.p, q * o.q);
        return res;
    }

    Func operator / (const Func &o) const {
        Func res = Func (p * o.q, q * o.p);
        return res;
    }

    Func operator + (const Func &o) const {
        Func res = Func (p * o.q + o.p * q, q * o.q);
        return res;
    }

    Func operator - (const Func &o) const {
        Func res = Func (p * o.q - o.p * q, q * o.q);
        return res;
    }
};

// std :: pair <Func, Func> f[N];
// int a[N], b[N];
// Func st[N][21];

// struct Node {
//     int w; Func g;
// } all[N];

int tree[M << 2], sub[M];

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + r >> 1)

void build (int p, int l, int r) {
    if (l == r) { tree[p] = l - sub[l]; return ; }
    build (ls, l, mid);
    build (rs, mid + 1, r);
    tree[p] = std :: min (tree[ls], tree[rs]);
}

int qry (int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return tree[p];
    int ret = 1e18;
    if (L <= mid) ret = std :: min (ret, qry (ls, l, mid, L, R));
    if (R > mid) ret = std :: min (ret, qry (rs, mid + 1, r, L, R));
    return ret;
}

namespace RunCode {
    // void solve () {
    //     // Func Min = Func (1);
    //     m = read (), n = read ();
    //     for (int i = 1; i <= n; i ++) {
    //         // int a, b;
    //         a[i] = read (), b[i] = read ();
    //         // #define a a[i]
    //         // #define b b[i]
    //         f[i] = {Func (a[i] - b[i], a[i]), Func (b[i], a[i])};
    //         // #undef a
    //         // #undef b
    //         // Min = std :: min (Min, f[i]);
    //     }
    //     // Func MinT = Func (Min.q - Min.p, Min.q);
    //     for (int i = 1; i <= m; i ++) {
    //         int w, p, q;
    //         w = read (), p = read (), q = read ();
    //         Func G = Func (q - p, q), Gi = Func (p, q);
    //         Func H = Gi * Func (w);
    //         Func res = Func (1e12);
    //         for (int j = 1; j <= n; j ++) {
    //             auto Min = f[j];
    //             int t = w / a[j] * a[j], o = w - t;
    //             Func T = w / a[j];
    //             if (w < a[j]) continue;
    //             // std :: cout << Min.first.q << std :: endl;
    //             Func ans = Func (t) * Min.first;
    //             if (Func (o) * Min.second * T > G * Func (w)) {
    //                 // std :: cout << 1 << std :: endl;
    //                 ans = H - Func (w / a[j] * b[j]);
    //             }
    //             // ans.re ();
    //             res = std :: min (res, ans);
    //             // std :: cout << ans.p << " " << ans.q << '\n';
    //             // std :: cout << i << std :: endl;
    //         }
    //         res = std :: min (H, res);
    //         print (res.p), putchar (' '), print (res.q), putchar ('\n');
    //     }
    // }

    void solve () {
        n = read (), m = read ();
        for (int i = 1; i <= m; i ++) {
            int a, b;
            a = read (), b = read ();
            sub[a] = std :: max (sub[a], b);
        }
        for (int i = 1; i < M; i ++) {
            for (int j = i; j < M; j += i) {
                sub[j] = std :: max (sub[j], sub[i] * (j / i));
            }
        }
        build (1, 1, M - 1);
        for (int i = 1; i < M; i ++) sub[i] = std :: max (sub[i], sub[i - 1]);
        for (int i = 1; i <= n; i ++) {
            int w = read (), p = read (), q = read ();
            Func G = Func (w * p, q);
            Func ans = std :: min (G - Func (sub[w * p / q]), Func (qry (1, 1, M - 1, w * p / q + 1, w)));
            print (ans.p), putchar (' '), print (ans.q), putchar ('\n');
        }
    }
}

signed main () {
    freopen ("discount.in", "r", stdin);
    freopen ("discount.out", "w", stdout);
    // std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/