#include <iostream>
using namespace std;
int i, dp[46]={1, 1};
inline void in(int &d) {
	char q;
	while ((q=getchar())==10);
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}

int main() {
	for (i=2; i<46; i++)
		dp[i] = dp[i-1] + dp[i-2];
	while (in(i), i)
		printf("%d\n", dp[i]);
}