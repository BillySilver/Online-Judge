#include <iostream>
int n, ls, rs, a, b;

inline void in(int &d) {
	char q;
	while (q=getchar(), q>57||q<48)
		if (q==-1) break;
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}

int main() {
	for (in(n); n; n-=2) {
		in(a), in(b);
		ls += a;
		rs += b;
	}
	puts(ls > rs ? "left" : "right");
}