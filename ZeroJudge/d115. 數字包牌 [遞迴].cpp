#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[100], i, now[101];
bool use[100];

inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

void dfs(int dep) {
	int j;
	if (dep==m) {
		for (j=1; j<=m; j++)
			printf("%d ",now[j]);
		putchar(10);
		return;
	}
	for (j=0; j<n; j++) {
		if (use[j] || now[dep]>a[j]) continue;
		now[dep+1] = a[j];
		use[j] = true;
		dfs(dep+1);
		use[j] = false;
	}
}

int main () {
	while (in(n), n) {
		for (i=0; i<n; i++)
			in(a[i]);
		in(m);
		sort(a, a+n);
		dfs(0);
	}
}