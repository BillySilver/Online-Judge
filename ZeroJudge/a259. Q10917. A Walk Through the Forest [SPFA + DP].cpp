#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#define MAX 2147483647
using namespace std;
int p[1001][1001], s[1001], n, dp[1001], snum[1001];
bool inq[1001];

bool cmp(int a, int b) {
	return s[a] < s[b];
}

int main () {
	int m, i, j, k, l;
	while (scanf ("%d" , &n) , n) {
		memset(p, 0, sizeof(p));
		memset(s, 0, sizeof(s));
		memset(dp, 0, sizeof(dp));
		scanf ("%d" , &m);
		for (i=1; i<=n; i++) {
			s[i] = MAX;
			snum[i] = i;
		}
		for (i=0; i<m; i++) {
			scanf("%d %d%d", &j, &k, &l);
			p[j][k]=p[k][j]=l;
		}
		queue<int> q;
		q.push(2);
		s[2] = 0;
		inq[2] = true;
		while (!q.empty()) {
			l = q.front();
			q.pop();
			for (i=1; i<=n; i++) {
				if (p[l][i] && s[i] > s[l]+p[l][i]) {
					s[i] = s[l]+p[l][i];
					if (!inq[i]) q.push(i);
					inq[i] = true;
				}
			}
			inq[l] = false;
		}
		sort(snum+1, snum+1+n, cmp);
		dp[2] = 1;
		for (i=1; i<=n; i++)
			for (j=1; j<i; j++)
				if (p[snum[i]][snum[j]] && s[snum[i]]!=s[snum[j]])
					dp[snum[i]] += dp[snum[j]];
		printf("%d\n", dp[1]);
	}
}