#include <iostream>
#include <stdio.h>
using namespace std;
int t, i, j, n, num, d[100], mx;

int gcd(int x, int y) {
	return x ? gcd(y%x, x) : y;
}

int main() {
	char q;	
	for (scanf("%d", &n),getchar(); n--;) {
		for (q=t=0; q-10; t++) {
			for (num=0; !isdigit(q=getchar());)
				if (!(q-10)||!~q) break;
			if (!(q-10)||!~q) break;
			do (num*=10)+=q^48;
			while (isdigit(q=getchar()));
			d[t] = num;
		}
		for (mx=i=0; i<t; i++)
			for (j=i+1; j<t; j++)
				mx = max(mx, gcd(d[i], d[j]));
		printf("%d\n", mx);
	}
}