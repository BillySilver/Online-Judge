#include <iostream>
using namespace std;
long long a, b;
long long gcd(long long x, long long y) {
	return (x%=y) ? gcd(y, x) : y;
}
inline void in(long long &d) {
	char q;
	while (!isdigit(q=getchar()))
		if(q==-1)break;
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (in(a),in(b),a)
		printf("%lld\n", a+b-gcd(a, b));
}