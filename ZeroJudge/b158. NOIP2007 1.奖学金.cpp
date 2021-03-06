#include <iostream>
#include <algorithm>
using namespace std;
int n, i;
struct data {
	int c, m, e, code, sco;
} stu[301];

bool cmp(data a, data b) {
	if (a.sco != b.sco)
		return a.sco > b.sco;
	if (a.c != b.c)
		return a.c > b.c;
	return a.code < b.code;
}

inline bool in(int &d) {
	char q;
	while (q=getchar(), q<48||q>57)
		if (q==-1) return false;
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
	return true;
}

int main() {
	while(in(n)) {
		for (i=0; i<n; i++) {
			in(stu[i].c), in(stu[i].m), in(stu[i].e);
			stu[i].sco = stu[i].c + stu[i].m + stu[i].e;
			stu[i].code = i+1;
		}
		sort (stu, stu+n, cmp);
		for (i=0; i<5; i++)
			printf("%d %d\n", stu[i].code, stu[i].sco);
	}
}
