#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, a, i;
string s;

inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (cin >> n) {
		for (s="",i=1; i<=n; s.append(a, i++|48))
			in(a);
		do printf("%s\n", s.c_str());
		while (next_permutation(s.begin(), s.end()));
	}
}