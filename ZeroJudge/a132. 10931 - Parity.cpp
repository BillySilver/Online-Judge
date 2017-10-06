#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int i, a, m;

int main() {
	while (scanf("%d",&a), a) {
		printf("The parity of ");
		for (i=1<<30; i>a; i>>=1);
		for (m=0; i; printf("%d", a/i),a%=i,i>>=1)
			if (a/i) m++;
		printf(" is %d (mod 2).\n", m);
	}
}