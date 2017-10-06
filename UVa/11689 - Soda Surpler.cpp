#include <stdio.h>
int N, e, f, c, n;

int main() {
	for (scanf("%d",&N); N--; ) {
		scanf("%d%d%d", &e, &f, &c);
		e += f;
		for (n=0; e>=c; ) {
			n += (f = e/c);
			e = e%c + f;
		}
		printf("%d\n", n);
	}
}