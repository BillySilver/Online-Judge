#include <iostream>
#include <stdio.h>
using namespace std;
int i, c, t;
long long dp[51][2];

int main() {
	dp[1][0] = dp[1][1] = 1;
	for (i=2; i<51; i++) {
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	for (scanf("%d",&t); t--; ) {
		scanf("%d", &i);
		printf("Scenario #%d:\n%lld\n\n", ++c, dp[i][0]+dp[i][1]);
	}
}