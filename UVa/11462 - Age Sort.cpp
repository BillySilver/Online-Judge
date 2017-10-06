#include <stdio.h>
int n, age, i, j;

int main() {
	while(scanf("%d",&n), n) {
		int a[101]={};
		for (i=0; i<n; i++)
			scanf("%d", &age), a[age]++;
		for (i=1; !a[i]; i++);
		printf("%d", i), a[i]--;
		for (; i<=100; i++) {
			if (!a[i]) continue;
			for (j=0; j<a[i]; j++)
				printf(" %d", i);
		}
		puts("");
	}
}