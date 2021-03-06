#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b, i, s[1000];
struct number {
	int num, q;
} m[1000];

inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

inline bool cmp(int x, int y) {
	return m[x].num==m[y].num ? m[x].q>m[y].q : m[x].num>m[y].num;
}

int main() {
	while (in(n), n) {
		for (i=0; i<n; s[i]=i++) {
			in(a), in(b);
			m[i].num = a + b;
			m[i].q = a>b ? 62 : a==b ? 61 : 60;
		}
		sort (s, s+n, cmp);
		for (i=0; i<n; i++)
			printf("%c%d ", m[s[i]].q ,m[s[i]].num);
		puts("");
	}
}
