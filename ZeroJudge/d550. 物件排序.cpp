#include <iostream>
#include <algorithm>
using namespace std;
int n, m, i, j, w;
void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
struct row {
	int b[200];
} a[10000];
int z[10000];

bool cmp(int x, int y) {
	for (w=0; a[x].b[w]==a[y].b[w]&&w<m; w++);
	return a[x].b[w] < a[y].b[w];
}
int main() {
	for (in(n),in(m),i=0; i<n; i++) {
		for (j=0; j<m; j++)
			in(a[i].b[j]);
		z[i] = i;
	}
	sort(z, z+n, cmp);
	for (i=0; i<n; puts(""),i++)
		for (j=0; j<m; j++)
			printf("%d ", a[z[i]].b[j]);
}
