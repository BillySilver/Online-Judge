#include <iostream>
using namespace std;
int n, s, p, x, i, knight[100001];

inline void in2(int &d) {
	char q;
	while (!isdigit(q=getchar())) {
		if (q!=-1) continue;
		d = -1;
		return;
	}
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (in2(n), n>-1) {
		while (n--)
			for (in(s),in(p); p--; knight[x] = s)
				in(x);
		in(x);
		printf("%d\n", knight[x]);
	}
}
