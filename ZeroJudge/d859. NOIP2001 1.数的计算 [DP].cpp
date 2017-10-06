#include <iostream>
int dp[1001]={0,1}, i, j, n;

int main() {
	std::cin >> n;
	for (i=2; i<=n; i++)
		for (dp[i]=j=1; j<=i/2; j++)
			dp[i] += dp[j];
	std::cout << dp[n];
}