#include <stdio.h>
unsigned long long n, m;
int main() {
	~scanf("%llu%llu", &n, &m)&&((n > m)&&!(n^=m^=n^=m)||printf("%llu\n", n*(n-1)/2*(n+1)/3*(2*m-n)/2))&&main();
}