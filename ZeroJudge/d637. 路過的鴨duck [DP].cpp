#include <iostream>
using namespace std;
int n, dp[101]={1}, v, c, mx, i;

inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
inline int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	for (in(n); n--; ) {
		in(v), in(c);
		for (i=100-v; i>=0; i--)
			if (dp[i])
				mx = max( dp[i+v]=max(dp[i+v], dp[i]+c), mx);
	}
	printf("%d", mx-1);
}