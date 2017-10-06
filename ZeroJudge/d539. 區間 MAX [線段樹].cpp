#include <iostream>
using namespace std;
int N, tree[1100000], t[500001], i, m, a, b;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
inline int MaxTree(int s, int e, int n) {
	if (s==e) 
		return tree[n] = t[s];
	return
		tree[n] = max( MaxTree(s, (s+e)/2, n*2) , MaxTree((s+e)/2+1, e, n*2+1) );
}
inline int findmax(int l, int r, int n, int s, int e) {
	if (l==s&&r==e)
		return tree[n];
	int mid = (l + r)/2;					//mid(中間位置)
	if (mid >= e)							//中間位置超過最右
		return findmax(l, mid, n*2, s, e);
	if (mid < s)							//中間位置超過最左
		return findmax(mid+1, r, n*2+1, s, e);
	return max(findmax(l, mid, n*2, s, mid), findmax(mid+1, r, n*2+1, mid+1, e));
}

int main() {
	for (in(N),i=1; i<=N; i++)
		in(t[i]);
	MaxTree(1, N, 1);
	for (in(m); m--; ) {
		in(a), in(b);
		if (a > b) swap(a, b);
		printf("%d\n", findmax(1, N, 1, a, b));
	}
}