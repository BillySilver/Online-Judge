#include <iostream>
using namespace std;
int k, m[101], n[101], i, j, mx, mi, mj, fib[45]={1,1};
inline int abs(int x) {
	return x > 0 ? x : -x;
}
int main() {
	for (i=2; i<=100; i++) {
		for (j=1; j<=i; j++) {
			if (abs(i*i-i*j-j*j)==1) {
				if (mx < i*i + j*j) {
					mx = i*i + j*j;
					mi = i;
					mj = j;
				}
			}
		}
		n[i] = mi;
		m[i] = mj;
	}
	for (i=2; i<45; i++)
		fib[i] = fib[i-1] + fib[i-2];
	while (scanf("%d", &k)==1) {
		for (i=0; k>=fib[i+1]; i++);
		printf("%d %d %d %d\n", m[k], n[k], fib[i-1], fib[i]);
	}
}