#include <iostream>
#include <algorithm>
using namespace std;
int a[100000], n, i, m, j;

inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	for (in(n),i=0; i<n; in(a[i++]));
	sort(a, a+n);
	for (i=0; i<n; printf("%d ", a[i++]));
}