#include <iostream>
int sum[2], i;
char s[1001], q;

inline void in(int &d) {
	char q;
	while (q=getchar(), q>57||q<48);
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (s[0]=q=getchar(), q!=48) {
		sum[0] = q^48;
		sum[1] = 0;
		for (i=1; s[i]=q=getchar(), q!=10; i++)
			sum[i%2] += q^48;
		s[i] = 0;
		printf("%s is%s a multiple of 11.\n", s, (sum[0]-sum[1])%11 ? " not" : "");
	}
}