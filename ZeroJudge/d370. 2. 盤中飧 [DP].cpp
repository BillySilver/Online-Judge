#include <iostream>
using namespace std;
int t, dp[20001], i, x, k; //0必贏 1必輸
bool ans;

int main() {
	for (scanf("%d",&t); t--; ) {
		scanf("%d%d", &x, &k);
		for (ans=0,i=1; i<k; i++)
			dp[i] = i&1;
		for (; i<=20000; i++)
			dp[i] = !(dp[i-k] || dp[i-1]);
		for (i=1; i<=10000&&!ans; i++)
			if (!(dp[x+i-1] || dp[x+i-k]))
				ans = true;
		printf("%d\n", ans ? --i: 0);
	}
}