#include <iostream>
using namespace std;
int i, j, k, cy[2000000]={0,1}, mx;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()))
		if(q==-1)break;
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
inline int dp(int x) {
	if (x >= 2000000) return 0;
	if (!cy[x]) {
		if (x==1) return 1;
		return cy[x] = (x%2) ? dp(3*x+1) + 1 : dp(x/2) + 1;
	}
	else return cy[x];
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	for (k=1; k<1000000; k++)
		if(!cy[k]) dp(k);
	while (in(i), i) {
		in(j);
		printf("%d %d ", i, j);
		if (i>j) swap(i, j);
		for (mx=0,k=i; k<=j; k++)
			mx = max(mx, cy[k]);
		printf("%d\n", mx);
	}
}