#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[101][101], t[2][101], n[2], i, j, cas;

int main() {
	while (scanf("%d%d",&n[0],&n[1]), n[1]) {
		if (cas) puts("");
		memset(dp, 0, sizeof(dp));
		for (j=0; j<2; j++)
			for (i=1; i<=n[j]; i++)
				scanf("%d", &t[j][i]);
		for (i=1; i<=n[0]; i++)
			for (j=1; j<=n[1]; j++)
				dp[i][j] = t[0][i]==t[1][j] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
		printf("Twin Towers #%d\nNumber of Tiles : %d\n", ++cas, dp[n[0]][n[1]]);
	}
}