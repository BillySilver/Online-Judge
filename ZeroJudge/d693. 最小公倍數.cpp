#include <iostream>
using namespace std;
long long N, n, record;

inline void in(long long &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

long long gcd(long long x, long long y) {
	return (x%=y) ? gcd(y, x) : y;
}

int main() {
	while (cin >> N, N) {
		for (cin >> record; --N; record=record*n/gcd(record, n))
			cin >> n;
		printf("%d\n", record);
	}
}