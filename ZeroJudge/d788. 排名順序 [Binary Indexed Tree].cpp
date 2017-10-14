#include <iostream>
using namespace std;
int BIT[100001], n, i, s;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()))
		if(q==-1) break;
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
inline void insert(int x) {
	while (x<=n) {
		BIT[x]++;
		x += (x&-x);
	}
}

inline int find(int x, int sum=0) {
	while (x) {
		sum += BIT[x];
		x -= (x&-x);
	}
	return sum;
}

int main() {
	while (in(n), n) {
		for (i=0; i<=n; BIT[i++]=0);
		for (i=1; i<=n; i++) {
			in(s);
			insert(s);
			printf("%d\n", i-find(s)+1);
		}
	}
}