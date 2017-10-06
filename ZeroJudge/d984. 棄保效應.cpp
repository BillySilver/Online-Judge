#include <iostream>
#include <algorithm>
using namespace std;

struct s {
	unsigned int d;
	char c;
}a[3];

bool m(s q, s w) {
	return q.d < w.d;
}

int main() {
	while (~scanf("%u%u%u",&a[0].d,&a[1].d,&a[2].d)) {
		a[0].c = 'A', a[1].c = 'B', a[2].c = 'C';
		sort(a, a+3, m);
		if (a[0].d + a[1].d > a[2].d) printf("%c\n", a[1].c);
		else printf("%c\n", a[2].c);
	}
}