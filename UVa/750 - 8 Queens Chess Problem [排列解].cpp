#include <cstdio>
#include <algorithm>
using namespace std;


int t, x, y, n, i, j;
bool cant;


int main() {
    for (scanf("%d", &t); t--; ) {
        int dp[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        n = !scanf("%d %d", &y, &x);
        puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
        for (--x, --y; next_permutation(dp, dp+8); ) {
            if (dp[x] != y) continue;
            for (cant = i = 0; !cant && i < 7; i++)
                for (j = 1; j < 8-i; j++)
                    if (dp[i]+j == dp[i+j] || dp[i]-j == dp[i+j])
                        cant = true;
            if (cant)
                continue;
            printf("%2d     ", ++n);
            for (i = 0; i < 8; i++)
                printf(" %d", dp[i]+1);
            putchar(10);
        }
        if (t)
            putchar(10);
    }
}
