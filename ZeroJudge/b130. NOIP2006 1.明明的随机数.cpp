#include <iostream>
#include <algorithm>
using namespace std;
int r[100], n, i, now;
bool num[1001];

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
		memset(num, 0, sizeof(num));
		for (now=0; n--; num[r[now]] ? r[now] = 0 : num[r[now++]] = true)
			in(r[now]);
		sort(r, r+now);
		printf("%d\n", now);
		for (i=0; i<now; i++)
			printf("%d ", r[i]);
		printf("\n");
	}
}