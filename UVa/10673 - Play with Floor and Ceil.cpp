#include <stdio.h>
int n, x, k;

int main() {
	for (scanf("%d",&n); n--; ) {
	    scanf("%d %d", &x, &k);
	    printf("%d %d\n", k-(x - x/k*k), x - x/k*k);
	}
}
