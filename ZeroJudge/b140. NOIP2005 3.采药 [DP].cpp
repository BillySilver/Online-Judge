#include <iostream>
int t, m, i, c, p, mx;

int max(int x, int y) {
	return x > y ? x : y;
}
int main() {
	while (~scanf("%d%d",&t,&m)) {
		int dp[1001]={};
		dp[0] = 1;
		mx = 0;
		while (m--) {
			scanf("%d%d", &c, &p);
			for (i=t-c; i>=0; i--)
				if (dp[i])
					mx = max( dp[i+c] = max(dp[i+c] , dp[i]+p ), mx);
		}
		printf("%d\n", mx-1);
	}
}