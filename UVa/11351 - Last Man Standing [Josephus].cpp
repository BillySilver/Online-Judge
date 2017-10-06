#include <stdio.h>
int t, cas, k, i;

int jsf(int n) {
	return n!=1 ? (k%n + jsf(n-1))%n : 0;
}

int main() {
	for (scanf("%d",&t); t--; ) {
		scanf("%d%d", &i, &k);
		printf("Case %d: %d\n", ++cas, jsf(i)+1);
	}
}