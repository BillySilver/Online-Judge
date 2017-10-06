#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int ac[3][1001], s[3], d[3], t, i, j, k, mxd, cas;
bool sol[3][10001];

bool elsesol(int v, int x) {
	for (int fi=0; fi<3; fi++)
		if (fi!=x && sol[fi][v])
			return true;
	return false;
}

int main() {
	for (scanf("%d",&t); t--; ) {
		memset(sol, 0, sizeof(sol));
		for (j=0; j<3; j++)
			for (scanf("%d",&s[j]),i=0; i<s[j]; sol[j][ac[j][i]]=true,i++)
				scanf("%d", &ac[j][i]);
		for (mxd=j=0; j<3; j++) {
			for (d[j]=i=0; i<s[j]; i++) {
				if (!elsesol(ac[j][i], j))
					d[j]++;
				else
					ac[j][i] = 2E4;
			}
			mxd = max(mxd, d[j]);
		}
		printf("Case #%d:\n", ++cas);
		for (j=0; j<3; j++) {
			if (d[j] != mxd) continue;
			printf("%d %d", j+1, d[j]);	
			sort (ac[j], ac[j]+s[j]);
			for (i=0; i<s[j]&&ac[j][i]!=20000; i++)
				printf(" %d", ac[j][i]);
			puts("");
		}
	}
}