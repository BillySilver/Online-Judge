#include <iostream>

long long dfs(int i, int j) {
	if (i<=2 && j<=2) {
		if (i==1) return j*2-1;
		return 2*(1+(j==1));
	}
	int d=(i>j?i:j)-1, k=1<<30;
	for (; !(d&k); k>>=1);
	if (i>k && j>k) return (long long)k*k + dfs(i-k, j-k);
	if (j>k) return (long long)k*k*2 + dfs(i, j-k);
	return (long long)k*k*3 + dfs(i-k, j);
}

int main() {
	int i, j;
	while (~scanf("%d%d",&i,&j))
		printf("%lld\n", dfs(i, j));
}


#include <stdio.h>

long long dfs(int i, int j) {
	if (i+j==2) return 1;
	long long d=(i>j?i:j)-1, k=1<<30, u;
	for (; !(d&k); k>>=1);
	u = k*k;
	if (i>k && j>k) return u + dfs(i-k, j-k);
	if (j>k) return u*2 + dfs(i, j-k);
	return u*3 + dfs(i-k, j);
}

int main() {
	int i, j;
	while (~scanf("%d%d",&i,&j))
		printf("%lld\n", dfs(i, j));
}