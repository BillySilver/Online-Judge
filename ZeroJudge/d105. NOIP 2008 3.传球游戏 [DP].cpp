#include <iostream>
int dp[31][31], n, m, i, j; //[傳第幾次][在第幾個人手上]

int main() {
	scanf("%d%d",&n,&m);
	dp[0][1] = 1;
	for (i=1; i<=m; i++) {
		dp[i][1] = dp[i-1][2] + dp[i-1][n];
		for (j=2; j<n; j++)
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
		dp[i][n] = dp[i-1][1] + dp[i-1][n-1];
	}
	printf("%d\n", dp[m][1]);
}