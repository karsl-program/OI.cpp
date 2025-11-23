#include <bits/stdc++.h>
const int N = 1e5 + 5;
int n, m, a[N], st[N][21], lg2[N];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline void print (int x) {
    if (x < 0) {
        putchar ('-');
        x = -x;
    }
    if (x > 9) print (x / 10);
    putchar (x % 10 + 48);
}

namespace RunCode {
    void solve () {
        lg2[1] = 0;
        for (int i = 2; i < N; i ++) lg2[i] = lg2[i >> 1] + 1;
        n = read (), m = read ();
        for (int i = 1; i <= n; i++) a[i] = read (), st[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j ++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i ++) {
                st[i][j] = std :: max (st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
        while (m --) {
            int l = read(), r = read();
            int k = lg2[r - l + 1];
            print (std :: max (st[l][k], st[r - (1 << k) + 1][k]));
            putchar ('\n');
        }
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/