#include <iostream>
using namespace std;
int hallo[42], n, m, i, a, mn;

inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (in(n), n) {
		for (memset(hallo,0,sizeof(hallo)); n--; )
			for (in(m); m--; hallo[a]++)
				in(a);
		for (mn=500,i=1; i<42; i++)
			mn = mn < hallo[i] ? mn : hallo[i];
		printf("%d\n", mn);
	}
}