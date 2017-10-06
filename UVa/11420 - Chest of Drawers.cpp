#include <iostream>
long long dp[66][66][2], n, s;		//[總櫃子][確保安全櫃子][最頂端鎖不鎖]

int main() {
	dp[1][0][0] = dp[1][1][1] = 1;
	for (n=2; n<66; n++) {
		//dp[n][0][0] = dp[n-1][0][0] + dp[n-1][1][1];
		//dp[n][n][1] = 1;
		for (s=0; s<=n; s++) {
			dp[n][s][0] = dp[n-1][s][0] + dp[n-1][s+1][1];
			dp[n][s][1] = dp[n-1][s-1][0] + dp[n-1][s-1][1];
		}
	}

	while (scanf("%lld%lld",&n,&s), n>0)
		printf("%lld\n", dp[n][s][0] + dp[n][s][1]);
}