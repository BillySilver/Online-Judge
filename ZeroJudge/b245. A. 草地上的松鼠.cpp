#include <iostream>
using namespace std;
int T, n, a, b, mx, k, i;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	in(T);
	while (T--) {
		in(n), in(a);
		for (mx=0,i=1; i<n; i++) {
			in(b);
			if (b-a>mx) {
				mx = b-a;
				k=i;
			}
			a=b;
		}
		printf("%d\n", k);
	}
}