#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[101], v, c, i, j, mx, n;

int main() {
	while (~scanf("%d",&n)) {
		memset(dp, 0, sizeof(dp));
		for (mx=dp[0]=1; n--; )
			for (scanf("%d%d",&v,&c),i=100-v; ~i; i--)
				if(dp[i])
					mx = max( dp[i+v] = max(dp[i]+c, dp[i+v]), mx );
		printf("%d\n", mx-1);
	}
}