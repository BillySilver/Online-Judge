#include <iostream>
#include <stdio.h>
unsigned long long dp[41] = {1, 1, 5}, n, i;

int main() {
	for (i=3; i<41; i++)
		dp[i] = dp[i-1] + dp[i-2]*4 + dp[i-3]*2;
	scanf("%llu",&n);
	while (n--) {
		scanf("%llu",&i);
		printf("%llu\n", dp[i]);
	}
}