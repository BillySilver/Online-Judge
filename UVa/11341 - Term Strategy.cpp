#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int L[11][101], t, n, m, i, j, k;

int main() {
	for (scanf("%d",&t); t--; ) {
		scanf("%d%d", &n, &m);
		for (i=1; i<=n; i++)
			for (j=1; j<=m; j++)
				scanf("%d", &L[i][j]);
		if (n > m) {
			puts("Peter, you shouldn't have played billiard that much.");
			continue;
		}
		int dp[11][101] = {1};
		for (i=1; i<=n; i++)
			for (j=m-n+1; L[i][j]>4&&j; j--)
				for (k=m-j; ~k; k--)
					if (dp[i-1][k])
						dp[i][k+j] = max(dp[i][k+j], dp[i-1][k]+L[i][j]);
		if (dp[n][m]) {
			i = (dp[n][m]-1) * 1000 / n;
			if (i%10>4) i+=10;
			i /= 10;
			printf("Maximal possible average mark - %d.%s%d.\n", i/100, i%100<10?"0":"", i%100);
		}
		else puts("Peter, you shouldn't have played billiard that much.");
	}
}