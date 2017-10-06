#include <iostream>
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
int main() {
	char c[2];
	int n, age, i, j;
	while(in(n), n) {
		int a[101]={};
		for (i=0; i<n; i++) { 
			in(age);
			a[age]++;
		}
		for (i=1; i<=100; i++) {
			if (!a[i]) continue;
			if (i/10) {
				c[0]=(i/10)|48, c[1]=(i%10)|48;
				for (j=a[i]; j>0; j--)
					putchar(c[0]), putchar(c[1]), putchar(32);
			}
			else {
				c[0]=i|48;
				for (j=a[i]; j>0; j--)
					putchar(c[0]), putchar(32);
			}
		}
		putchar(10);
	}
}