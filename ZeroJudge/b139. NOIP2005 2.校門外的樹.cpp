#include <iostream>
int l, m, s, e, i;
bool none[10001];

inline void in(int &d) {
	char q;
	while (q=getchar(), q>57||q<48)
		if (q==-1) break;
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}

int main() {
	for (in(l),in(m); m--; )
		for (in(s),in(e); s<=e; s++)
			none[s] = true;
	for (m=i=0; i<=l; i++)
		m += !none[i];
	printf("%d", m);
}