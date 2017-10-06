#include <iostream>
unsigned long long n;
int main() {
	while (~scanf("%llu", &n))
		printf("%llu\n", n*(n-1)/2*(n+1)/3*n/2);
}