#include <stdio.h>

int main() {
	int t, m, n;
	for (scanf("%d",&t); t--; ) {
		scanf("%d %d", &n, &m);
		if ((n-1)%(m-1))
			printf("cannot do this\n");
		else
			printf("%d\n",(n-1)/(m-1));
	}
}