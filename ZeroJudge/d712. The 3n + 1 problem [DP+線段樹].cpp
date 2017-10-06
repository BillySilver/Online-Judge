#include <iostream>
using namespace std;
int N, Maxtree[4000000], cy[2000000]={0,1}, m, i, j, k;
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
inline int MaxTree(int s, int e, int n) {
	if (s==e) 
		return Maxtree[n] = cy[s];
	return
		Maxtree[n] = max( MaxTree(s, (s+e)/2, n*2) , MaxTree((s+e)/2+1, e, n*2+1) );
}
inline int findmax(int l, int r, int n, int s, int e) {
	if (l==s&&r==e)
		return Maxtree[n];
	int mid = (l + r)/2;					//mid(中間位置)
	if (mid < s)							//中間位置超過最左
		return findmax(mid+1, r, n*2+1, s, e);
	if (mid >= e)							//中間位置超過最右
		return findmax(l, mid, n*2, s, e);
	return max(findmax(l, mid, n*2, s, mid), findmax(mid+1, r, n*2+1, mid+1, e));
}
inline int dp(long long x) {
	if (x >= 1000000)
		return (x%2) ? dp(3*x+1) + 1 : dp(x/2) + 1;
	if (!cy[x]) {
		if (x==1) return 1;
		return cy[x] = (x%2) ? dp(3*x+1) + 1 : dp(x/2) + 1;
	}
	else return cy[x];
}

int main() {
	for (k=1000000; k>=1; k--)
		if(!cy[k]) dp(k);
	MaxTree(1, 1000000, 1);
	while (in(i), i) {
		in(j);
		printf("%d %d ", i, j);
		if (i>j) swap(i, j);
		printf("%d\n", findmax(1, 1000000, 1, i, j));
	}
}