#include <iostream>
int money[10]={1,5,10,30,50,70,100,110,500,1000}, dp[1000], T, n;

inline void in(int &d) {
	char q;
	while (q=getchar(), q>57||q<48);
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}
inline int min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	for (n=1; n<1000; n++)
		dp[n] = n;
	for (T=1; T<9; T++)
		for (n=money[T]; n<1000; n++)
			dp[n] = min(dp[n-money[T]]+1, dp[n]);
	for (in(T); T--; printf("%d\n",n/1000+dp[n%1000]))
		in(n);
}