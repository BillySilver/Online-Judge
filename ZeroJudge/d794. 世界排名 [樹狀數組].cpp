#include <iostream>
#include <algorithm>
using namespace std;
int BIT[100001];
unsigned long long num[100001], sor[100001], n;
inline void in(unsigned long long &d) {
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
inline int search(int x, int l=1, int r=n) {
	if (l==r) return l;
	int m = (l + r)/2;
	if (x < sor[m]) return search(x, l, m);
	if (x > sor[m]) return search(x, m+1, r);
	return m;
}

int main() {
	int i, s;
	while (in(n), n) {
		for (i=1; i<=n; BIT[i++]=0) {
			in(num[i]);
			sor[i] = num[i];
		}
		sort(sor, sor+n+1);
		for (i=1; i<=n; i++) {
			s = search(num[i]);
			insert(s);
			printf("%d\n", i-find(s)+1);
		}
	}
}