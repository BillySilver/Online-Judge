#include <iostream>
#include <algorithm>
using namespace std;
int n, a[50000], i, x;

inline void in(int &d) {
	bool sign=0;
	char q;
	while (!isdigit(q=getchar()))
		if (q=='-') sign = true;
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
	if (sign) d = -d;
}

int main() {
	while (in(n), n) {
		for (i=0; i<n; i++)
			in(a[i]);
		sort(a, a+n);
		for (x=a[1]-a[0],i=2; i<n&&a[i]-a[i-1]==x; i++);
		puts(i==n||n==1 ? "Yes" : "No");
	}
}