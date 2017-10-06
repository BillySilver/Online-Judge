#include <iostream>
#include <stdio.h>
int n, m, c, i, e[21], mx, blw, now, t;
inline int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	while(scanf("%d%d%d",&n,&m,&c), n) {
		bool use[21]={};
		for (i=1; i<=n; i++)
			scanf("%d", &e[i]);
		for (now=blw=mx=i=0; i<m; i++) {
			scanf("%d", &n);
			if (!use[n]) {
				mx = max((now += e[n]), mx);
				if (now > c) blw = 1;
				use[n] = true;
			}
			else {
				now -= e[n];
				use[n] = false;
			}
		}
		printf("Sequence %d\nFuse was %sblown.\n", ++t, blw ? "" : "not ");
		if (!blw) printf("Maximal power consumption was %d amperes.\n\n", mx);
		else puts("");
	}
}