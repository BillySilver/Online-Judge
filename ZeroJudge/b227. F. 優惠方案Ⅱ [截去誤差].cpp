#include <iostream>
int T, n, p, a, b;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	in(T);
	while (T--) {
		in(n), in(p);
		a = n*p*1000 - (n/2)*p*400;
		b = n*p*812;
		if (a%1000) a+=1000;
		if (b%1000) b+=1000;
		a/=1000, b/=1000;
		puts(a < b ? ": )" : a > b ? "8-12=-4" : "SAME");
	}
}