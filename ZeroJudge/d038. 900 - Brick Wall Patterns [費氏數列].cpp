#include <iostream>
using namespace std;
long long n, dp[51] = {1,1};
inline void in(long long &d) {
	char q;
	while ((q=getchar())==10);
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}

inline long long fib(long long x){
	return !dp[x] ? dp[x] = fib(x-1) + fib(x-2) : dp[x];
}

int main() {
	while (in(n), n)
		printf("%llu\n", fib(n));
}