#include <iostream>
#include <stdio.h>
using namespace std;
int m, c, i, j, k, l, ans;

int main() {
	for (scanf("%d",&m); ~scanf("%d%d",&m,&c); ) {
		bool dp[21][201]={1};
		for (i=1; i<=c; i++)
			for (scanf("%d",&j); j--; )
				for (scanf("%d", &k),l=k; l<=m; l++)
					if (dp[i-1][l-k])
						dp[i][l] = true;
		for (ans=m; !dp[c][ans]&&ans; ans--);
		if (ans) printf("%d\n", ans);
		else puts("no solution");
	}
} 