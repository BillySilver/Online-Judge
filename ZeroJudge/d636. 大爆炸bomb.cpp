#include <iostream>
int x, y, MOD = 10007;
inline int pow(int a, int n) {
	if (n==1)
		return a;
	int k = pow(a, n/2);
	k *= k;
	if (k >= MOD) k %= MOD;
	if (n&1)
		if ( (k*=a) && k >= MOD) k %= MOD;
	return k;
}
int main() {
	scanf("%d%d",&x,&y);
	printf("%d",pow(x%MOD, y));
}