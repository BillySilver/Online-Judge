#include <iostream>
using namespace std;
int n, i, lk;

struct tree {
	int d, l, r;
} t[1001];

void visit(int k) {
	if (!k) return;
	printf(" %d",t[k].d);
	visit(t[k].l);
	visit(t[k].r);
}

int main() {
	while (~scanf("%d", &n)) {
		memset(t, 0, sizeof(t));
		for (i=scanf("%d", &t[0].d); i<n; i++) {
			lk = !scanf("%d", &t[i].d);
			while (1) {
				if (t[i].d < t[lk].d)
					if (t[lk].l) lk = t[lk].l;
					else {
						t[lk].l = i;
						break;
					}
				else
					if (t[lk].r) lk = t[lk].r;
					else {
						t[lk].r = i;
						break;
					}
			}
		}
		printf("%d", t[0].d);
		visit(t[0].l);
		visit(t[0].r);
		puts("");
	}
}