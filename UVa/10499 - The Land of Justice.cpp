#include <stdio.h>
long long n;

int main() {
	while (scanf("%lld",&n), n>0) {
	    if (n == 1) puts("0%");
	    else printf("%lld%%\n", n*25);
	}
}
