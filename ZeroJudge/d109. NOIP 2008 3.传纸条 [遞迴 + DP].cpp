#include <iostream>
int dp[50][50][50][50], map[50][50], m, n, i, j, k, l;

inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

inline int max(int x, int y) {
	return x > y ? x : y;
}

int dfs(int x1, int y1, int x2, int y2) {
	if (!~x1 || !~y1 || !~x2 || !~y2 || x1==x2&&y1==y2)
		return 0;
	return dp[x1][y1][x2][y2] ? dp[x1][y1][x2][y2] : dp[x1][y1][x2][y2] = max( max(dfs(x1-1,y1,x2-1,y2), dfs(x1-1,y1,x2,y2-1)), max(dfs(x1,y1-1,x2-1,y2), dfs(x1,y1-1,x2,y2-1)) ) + map[y1][x1] + map[y2][x2];
}

int main() {
	in(m), in(n);
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			in(map[i][j]);
	printf("%d\n", dfs(n-2, m-1, n-1, m-2));
}