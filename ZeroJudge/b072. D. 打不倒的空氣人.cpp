#include <iostream>
#include <string>
using namespace std;
int n, m, i;
string ans, a;
inline void Sin(string &d) {
	char q;
	while (q=getchar(), q==10||q==32);
	for (; q!=10&&q!=32; q=getchar())
		d += q;
}
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (in(n), in(m), n) {
		for (ans="",i=0; i<n; i++)
			Sin(ans);
		for (a="",i=0; i<m; i++) {
			in(n);
			a += ans[n-1];
		}
		printf("%s\n", a.c_str());
	}
}