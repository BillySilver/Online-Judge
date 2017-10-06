#include <iostream>
int a[100000], n, k, i, x, m;
inline void in(int &d) {
	bool sign = false;
	char q;
	while (!isdigit(q=getchar()))
		if (q=='-') {q=getchar(); sign = true; break;}
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
	if (sign) d = -d;
}

inline int search(int l, int r) {
	if (l > r) return 0;
	m = (l + r)/2;
	if (x < a[m]) return search(l, m-1);
	if (x > a[m]) return search(m+1, r);
	return m;
}

int main() {
	in(n), in(k);
	for (i=1; i<=n; i++)
		in(a[i]);
	for (i=0; i<k; i++) {
		in(x);
		printf("%d\n", search(1, n));
	}
}