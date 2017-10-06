#include <iostream>
#include <algorithm>
using namespace std;
int stone[1000000], n, i, m;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar())&&q!=-1);
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	for (n=0; in(stone[n]), stone[n]; n++);
	sort(stone, stone+n);
	for (m=i=1; i<n; i++) {
		if (stone[i]==stone[i-m])
			m++;
		else {
			if (m%3) break;
			m = 1;
		}
	}
	printf("%d", stone[i-1]);
}