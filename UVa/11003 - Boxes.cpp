#include <iostream>
#include <string.h>
using namespace std;
int b[1000][2], dp[1000][1001], n, i, j;

int main() {
	while (cin >> n, n) {
		memset(dp, 0, sizeof(dp));
		for (i=n-1; ~i; i--)
			cin >> b[i][0] >> b[i][1];
		dp[0][1] = b[0][0];
		for (i=0; i<n-1; i++) {
			dp[i+1][1] = min(dp[i][1], b[i+1][0]);
			for (j=1; j<=i+1; j++) {
				if (dp[i][j] <= b[i+1][1])
					dp[i+1][j+1] = dp[i][j] + b[i+1][0];
				dp[i+1][j] = dp[i+1][j] ? min(dp[i+1][j], dp[i][j]) : dp[i][j];
				if (!dp[i][j+1]) break;
			}
		}
		for (j=n; !dp[n-1][j]; j--);
		cout << j << endl;
	}
}