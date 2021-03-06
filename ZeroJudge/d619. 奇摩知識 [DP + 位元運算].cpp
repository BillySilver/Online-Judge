#include <iostream>
using namespace std;
int n, i, j;
long long binary_1[28], sum;
inline void in(int &d) {
	char q;
	while ((q=getchar())==10);
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}
void dfs(int n, int i) {
	if (!n) return;
	if (n & (1 << i)) {
		n = n - (1 << i);
		sum += binary_1[i] + n + 1;
	}
	dfs(n, i-1);
}

int main() {
	for (i=1; i<28; i++)
		binary_1[i] = binary_1[i-1]+binary_1[i-1] + (1 << i-1);
	while (in(n), n) {
		for (i=31; !((n>>i)&1); i--);
		sum = 0;
		dfs(n, i);
		printf("%d\n", sum%1000000000);
	}
}