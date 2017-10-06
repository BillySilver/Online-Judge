#include <iostream>
#include <algorithm>
using namespace std;
int n, c, i, j, dp[1001]={1}, ct[10];

int main() {
	scanf("%d%d", &c, &n);
	for (i=0; i<n; i++)
		scanf("%d", &ct[i]);
	sort(ct, ct+n);
	for (i=0; i<n; i++)
		for (j=ct[i]; j<=c; j++)
			if (dp[j-ct[i]])
				dp[j] = dp[j] ? min(dp[j], dp[j-ct[i]]+1) : dp[j-ct[i]]+1;
	printf("%d\n", dp[c]-1);
};