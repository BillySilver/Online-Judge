#include <iostream>
int n, m, i, j;
unsigned long long dp[91][16], sum;

int main() {
	while (~scanf("%d%d", &n, &m)) {
		memset(dp, 0, sizeof(dp));
		dp[1][0] = dp[1][1] = 1;
		for (i=2; i<=n; i++)
			for (j=1; j<=i; j++)
				dp[i][0] += (dp[i][j] = dp[i-1][j-1]);
		for (; i<=m; i++)
			for (dp[i][0]=dp[i-1][n], j=1; j<=n; j++)
				dp[i][0] += (dp[i][j] = dp[i-1][j-1]);
		for (sum=j=0; j<=n; j++)
			sum += dp[m][j];
		printf("%llu\n", sum);
	}
}