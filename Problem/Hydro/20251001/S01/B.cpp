#include <bits/stdc++.h>

int n, k, cnt[256][256][256], sum[256][256][256];

namespace RunCode {
    void init () {
        for (int i = 0; i < 256; i++) { // x
            for (int j = 0; j < 256; j++) {
                for (int k = 0; k < 256; k++) {
                    if (i > 0) {
                        sum[i][j][k] = sum[i-1][j][k] + cnt[i][j][k];
                    } else {
                        sum[i][j][k] = cnt[i][j][k];
                    }
                }
            }
        }
        
        for (int i = 0; i < 256; i++) { // y
            for (int j = 0; j < 256; j++) {
                for (int k = 0; k < 256; k++) {
                    if (j > 0) {
                        sum[i][j][k] += sum[i][j-1][k];
                    }
                }
            }
        }
        
        for (int i = 0; i < 256; i++) { // z
            for (int j = 0; j < 256; j++) {
                for (int k = 0; k < 256; k++) {
                    if (k > 0) {
                        sum[i][j][k] += sum[i][j][k-1];
                    }
                }
            }
        }
    }

    int get_sum (int r1, int g1, int b1, int r2, int g2, int b2) {
        int tot = sum[r2][g2][b2];
        
        if (r1 > 0) tot -= sum[r1-1][g2][b2];
        if (g1 > 0) tot -= sum[r2][g1-1][b2];
        if (b1 > 0) tot -= sum[r2][g2][b1-1];
        
        if (r1 > 0 && g1 > 0) tot += sum[r1-1][g1-1][b2];
        if (r1 > 0 && b1 > 0) tot += sum[r1-1][g2][b1-1];
        if (g1 > 0 && b1 > 0) tot += sum[r2][g1-1][b1-1];
        
        if (r1 > 0 && g1 > 0 && b1 > 0) tot -= sum[r1-1][g1-1][b1-1];
        
        return tot;
    }

    bool check (int D) {
        for (int r = 0; r + D < 256; r++) {
            for (int g = 0; g + D < 256; g++) {
                for (int b = 0; b + D < 256; b++) {
                    int r2 = r + D, g2 = g + D, b2 = b + D;
                    int tot = get_sum(r, g, b, r2, g2, b2);
                    if (tot >= k) return true;
                }
            }
        }
        return false;
    }

    void solve () {
        freopen ("rgb.in", "r", stdin);
        freopen ("rgb.out", "w", stdout);

        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            int R, G, B;
            scanf("%d%d%d", &R, &G, &B);
            cnt[R][G][B] ++;
        }

        init ();

        int left = 0, right = 255;
        while (left < right) {
            int mid = (left + right) / 2;
            if (check (mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        printf("%d\n", left);
    }
}

int main () {
    RunCode :: solve ();

    return 0;
}

/*

Programming is the art of telling another human being what one wants the computer to do.    -- Donald Knuth

*/