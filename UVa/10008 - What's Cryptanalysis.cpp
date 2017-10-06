#include <iostream>
#include <algorithm>
using namespace std;
int n, i;
char a;
struct acsii {
	int num;
	char c;
} x[27];

inline void in(int &d) {
	char q;
	while (q=getchar(), q>57||q<48);
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}
bool cmp(acsii d, acsii f) {
	return d.num == f.num ? d.c < f.c : d.num > f.num;
}

int main() {
	for (i=1; i<27; i++)
		x[i].c = i|64;
	for (in(n); n--; ) {
		while (a=getchar(), a!=10) {
			if(!isalpha(a)) continue;
			a = a<=90 ? a^64 : a-96;
			x[a].num++;
		}
	}
	sort (x, x+27, cmp);
	for (i=0; x[i].num; i++)
		printf("%c %d\n", x[i].c, x[i].num);
}
