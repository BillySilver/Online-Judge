#include <iostream>
int cnt[10000001], ans[10000072], sod, T, n, m, c;

inline void in(int &d) {
	char q;
	while (q=getchar(), q>57||q<48);
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
	if (q!=10) in(m);
}
inline int fun(int a, int b) {
	if (b)
		return cnt[b]-cnt[a-1];
	else
		return ans[a] ? ans[a] : -1;
}

int main() {
	for (n=1; n<10000001; n++) {
		for (sod=0,T=n; T; T/=10)
			sod += T%10;
		if (!ans[n + sod]) ans[n + sod] = n;
		cnt[n] = cnt[n-1] + !ans[n];
	}
	for (scanf("%d",&T); T--; ) {
		m = 0, in(n);
		printf("Case %d: %d\n", ++c, fun(n, m));
	}
}