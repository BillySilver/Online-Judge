#include <iostream>
int fib[9]={122522400, 2227680, 65520, 3120, 240, 30, 6, 2, 1}, n, i;
//每一項都是費氏數列階乘 1, 1*2, 1*2*3, 1*2*3*5, 1*2*3*5*8...
inline void in(int &d) {
	char q;
	while (q=getchar(), q>57||q<48)
		if(q==-1)break;
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (in(n), n) {
		for (i=0; !(n/fib[i]); i++);
		printf("%d", n/fib[i]);
		n %= fib[i++];
		for (; i<9; n%=fib[i++]) 
			printf(",%d", n/fib[i]);
		puts("");
	}
}