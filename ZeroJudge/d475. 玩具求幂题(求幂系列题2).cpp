#include <iostream>
int a, n, i;
char lp[10000];
inline int exp(int x, int y) {
	if (!y) return 1;
	int k = exp(x, y/2);
	k *= k;
	if (y&1) k *= x;
	return k;
}

int main() {
	while (scanf("%d%d",&a,&n), a||n) 
		printf("%d\n", exp(a, n));
	for (i=0; gets(lp); i++);
	printf("All Over. Exceeded %d lines!", i-1);
}