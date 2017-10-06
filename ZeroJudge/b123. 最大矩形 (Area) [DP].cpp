#include <iostream>
int m, n, area[201][201], i, j, k, mx, mn, h;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()))
		if (q==-1)break;
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
inline int min(int x, int y) {
	return x < y ? x : y;
}
inline int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	while(in(m), m) {
		in(n);
		for (mx=j=1; j<=m; j++)
			for (i=1; i<=n; i++)
				if (in(area[j][i]), area[j][i])
					area[j][i] += area[j][i-1];
		for (i=n; i>0; i--) {
			for (k=m; k>0; k--) {
				for (h=1,j=k,mn=n; j>0; j--) {
					if (area[j][i]) {
						mn = min(area[j][i], mn);
						mx = max(h++*mn, mx);
						continue;
					}
					mn = n;
					h = 1;
				}
			}
		}
		printf("%d\n", mx);
	}
}