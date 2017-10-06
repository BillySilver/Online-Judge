#include <stdio.h>
int n;
unsigned long long a, b;

int main() {
	while (scanf("%llu%llu", &a, &b), a)
	    printf("Case %d: %llu\n", ++n, a*(a-1)/2*b*(b-1)/2);
}
