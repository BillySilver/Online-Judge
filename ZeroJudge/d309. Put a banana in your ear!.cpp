//公式 : Sigma(n-1) * 2^(n-1)
#include <iostream>
#define MOD 1000000007
long long n;

inline int bipow(int e) {
	if (!e)	return 1;
	long long k = bipow(e>>1);
	k *= k;
	if (k >= MOD) k %= MOD;
	if (e&1)
		if ( (k<<=1) && k >= MOD) k %= MOD;
	return k;
}

int main () {
	while (~scanf("%d",&n))
		printf("%d\n", (n*(n-1)>>1)%MOD * bipow((int)n-1)%MOD);
}