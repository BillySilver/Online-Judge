#include <iostream>
long long a;

int main() {
	while (scanf("%lld",&a), a>=0)
		printf("%lld\n", a*(a+1)/2+1);
}