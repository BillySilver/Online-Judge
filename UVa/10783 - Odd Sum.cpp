#include <iostream>
int oddsum[102], T, a, b, c;

inline void in(int &d) {
	char q;
	while (q=getchar(), q>57||q<48);
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}

int main() {
	for (a=1; a<100; a+=2)
		oddsum[a+2] = oddsum[a+1] = oddsum[a] + a;
	for (in(T); T--; printf("Case %d: %d\n", ++c, oddsum[b+1]-oddsum[a]))
		in(a), in(b);
}