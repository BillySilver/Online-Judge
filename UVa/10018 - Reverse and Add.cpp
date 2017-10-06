#include <iostream>
using namespace std;
long long n, m, d, sum, y;
inline void in(long long &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
inline long long reverse(long long x) {
	for (y=0; x; x/=10)
		(y*=10) += x%10;
	return y;
}

int main() {
	for (in(n); n--; printf("%lld %lld\n", sum, m)) {
		in(m);
		m += reverse(m);
		for (sum=1; m != (d=reverse(m)); sum++)
			m += d;
	}
}