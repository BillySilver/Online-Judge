#include <stdio.h>
int i, j;
unsigned long long dp[101][64], k;	//[逞緇瞴计][メ耏Ω计] = 程代眔加糷计秖

int main() {
	for (i=1; i<=100; i++)
		for (j=1; j<64; j++)
			dp[i][j] = dp[i][j-1] + 1 + dp[i-1][j-1];
	for (; scanf("%d%llu",&i,&k),i; j<64 ? printf("%d\n", j) : puts("More than 63 trials needed."))
		for (j=0; j<64&&dp[i][j]<k; j++);
}