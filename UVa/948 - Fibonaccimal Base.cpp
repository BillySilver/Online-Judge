#include <iostream>
#include <stdio.h>
using namespace std;
int f[38]={1, 2}, i, t, a;

int main() {
	for (i=2; i<38; i++)
		f[i] = f[i-1] + f[i-2];
	for (scanf("%d",&t); t--; ) {
		scanf("%d", &a);
		printf("%d = ", a);
		for (i=37; f[i]>a; i--);
		for ( ; ~i; i--)
			if (f[i] <= a)
				printf("1"), a -= f[i];
			else printf("0");
		puts(" (fib)");
	}
}