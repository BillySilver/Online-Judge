#include <cstdio>


int dp[77], i, j;


int main() {
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (i = 3; i <= 76; i++) {
        dp[i] = dp[i-2] + dp[i-3];
    }
    while (~scanf("%d", &i)) {
        printf("%d\n", dp[i]);
    }
}
