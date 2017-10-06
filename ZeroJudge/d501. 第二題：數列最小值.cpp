#include <iostream>
#include <algorithm>
using namespace std;
int x[1000000], n, i, t;
bool st(int a, int b) {
	return a < b;
}

int main() {
	while (~scanf("%d", &n)) {
		for (i=0; i<n; i++)
			scanf("%d", &x[i]);
		sort(x, x+n, st);
		printf("A=%d", t=x[(n-1)/2]);
		if (!(n&1))
			for (t++; t<=x[n/2]; t++)
				printf("、%d", t);
		puts("");
	}
}