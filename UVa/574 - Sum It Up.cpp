#include <iostream>
#include <stdio.h>
using namespace std;
int t, n, s[12][2], i, j, num, use[13];
bool can;

void dfs(int sum, int d) {
	if (d-1 == n || sum > t) return;
	if (sum == t) {
		can = true;
		for (i=0; i<d; i++) {
			if (!use[i]) continue;
			printf("%d", s[i][0]);
			for (j=1; j<use[i]; j++)
				printf("+%d", s[i][0]);
			i++;
			break;
		}
		for (; i<d; i++)
			if (use[i])
				for (j=0; j<use[i]; j++)
					printf("+%d", s[i][0]);
		puts("");
		return;
	}
	for (int k=s[d][1]; k>=0; k--) {
		use[d] = k;
		dfs(sum+s[d][0]*k, d+1);
	}
}

int main() {
	while (scanf("%d%d", &t, &n), t+n) {
		printf("Sums of %d:\n", t);
		scanf("%d",&s[0][0]);
		s[0][1] = 1;
		for (j=0,i=1; i<n; i++) {
			scanf("%d",&num);
			if (s[j][0] == num)
				s[j][1]++;
			else {
				s[++j][0] = num;
				s[j][1] = 1;
			}
		}
		n = j+1;
		can = false;
		dfs(0, 0);
		if (!can)
			printf("NONE\n");
	}
}