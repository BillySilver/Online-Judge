#include <iostream>
#include <string>
using namespace std;
int n, i, j, maxl;
string s[100];

inline int max(int x, int y) {
	return x > y ? x : y;
}
inline void in(string &d) {
	char q;
	while (q=getchar(), q==10);
	for (d=""; q!=10&&q!=-1; q=getchar())
		d += q;
	maxl = max(maxl, d.size());
}

int main() {
	for (n=0; in(s[n]),s[n]!=""; n++);
	for (i=0; i<n; i++)
		s[i].append(maxl-s[i].size(), 32);
	for (i=0; i<maxl; i++) {
		for (j=n-1; j>=0; j--)
			printf("%c", s[j][i]);
		puts("");
	}
}