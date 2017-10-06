#include <iostream>
#include <stdio.h>
using namespace std;
int dp[352][27][27], c; //sigma(1,26)=351

int main() {
	int i, j, k, l;
	dp[0][0][0] = 1;
	for (i=1; i<=351; i++)
		for (j=1; i>=j&&j<=26; j++)
			for (l=1; l<=26; l++)
				for (k=0; k<j; k++)
					dp[i][l][j] += dp[i-j][l-1][k];
	for (i=1; i<=351; i++)
		for (j=1; j<=26; j++)
			for (k=1; k<=26; k++)
				dp[i][j][0] += dp[i][j][k];
	while (scanf("%d%d",&i,&j), i+j)
		printf("Case %d: %d\n", ++c, i>26||j>351?0:dp[j][i][0]);
}