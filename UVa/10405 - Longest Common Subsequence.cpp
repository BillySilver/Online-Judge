#include <iostream>
using namespace std;
int dp[1001][1001], i, j, z1, z2;
char s1[1001], s2[1001];

int main() {
	while (gets(s1)) {
		gets(s2);
		z1 = strlen(s1), z2 = strlen(s2);
		for (i=0; i<z1; i++) {
			for (j=0; j<z2; j++) {
				if (s1[i] == s2[j])
					dp[i+1][j+1] = dp[i][j] + 1;
				else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
		}
		printf("%d\n", dp[z1][z2]);
	}