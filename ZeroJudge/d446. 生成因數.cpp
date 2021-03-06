#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n, s, i, now, d[1000000];
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()))
		if(q==-1) break;
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (in(n), n) {
		if (n==1) {
			printf("1\n");
			continue;
		}
		s = sqrt((float)n);
		d[0] = 1, d[1] = n;
		for (now=i=2; i<=s; i++) {
			if (n%i) continue;
			d[now++] = i;
			if (i*i==n) continue;
			d[now++] = n/i;
		}
		sort(d, d+now);
		for (i=0; i<now; i++)
			printf("%d ", d[i]);
		printf("\n");
	}
}