#include <iostream>
using namespace std;
int i, j, k, mx, cy, c;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()))
		if(q==-1)break;
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	while (in(i), i) {
		in(j);
		printf("%d %d ", i, j);
		if (i>j) swap(i, j);
		for (mx=0,k=i; (c=k)<=j; k++) {
			for (cy=1; c!=1; cy++)
				c = c%2 ? c*3+1 : c/2;
			mx = max(mx, cy);
		}
		printf("%d\n", mx);
	}
}