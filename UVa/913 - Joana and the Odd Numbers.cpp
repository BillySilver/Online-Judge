#include <iostream>

int main() {
	long long a;	
	while (scanf("%lld",&a)==1) {
		a = (a+1) >> 1;
		printf("%lld\n", 6*a*a-9);
	}
}