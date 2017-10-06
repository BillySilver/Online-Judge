#include <iostream>
int dp[77], i, j;

int main() {
	dp[2]=(dp[0]=dp[1]=1)+1;
	for (i=3; i<=76; i++)
		dp[i] = dp[i-2] + dp[i-3];
	while (~scanf("%d",&i))
		printf("%d\n", dp[i]);
}