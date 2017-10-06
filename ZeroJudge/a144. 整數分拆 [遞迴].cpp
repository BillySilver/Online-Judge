#include <iostream>
using namespace std;
int a[100], N;

void divide(int n, int i, int mn) {
	int j;
	if (!n) {
		for (j=0; j<i; j++)
			printf("%d ", a[j]);
		puts("");
		return;
	}
	for (j=mn; j; j--) {
		if (n<j) continue;
		a[i] = j;
		divide(n-j, i+1, mn<j?mn:j);
	}
}

int main() {
	while (~scanf("%d",&N))
		if (N) divide(N, 0, N);
		else puts("0");
}