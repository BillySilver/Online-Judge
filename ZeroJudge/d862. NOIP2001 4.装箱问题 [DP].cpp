#include <iostream>
int v, n, i, vi, mx;
bool b[20001]={true};
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar())&&q!=-1);
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
inline int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	in(v), in(n);
	while (n--) {
		in(vi);
		for (i=v; i>=vi; i--) {
			if (b[i-vi]) {
				b[i] = true;
				mx = max(mx, i);
			}
		}
	}
	printf("%d", v-mx);
}