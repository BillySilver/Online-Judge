#include <stdio.h>
int i, v, b, s;
char c[33];
inline bool in(int &d, char q=0, bool sign=0) {
	while(q=getchar(), q<48||q>57) {
		if (q==-1) return false;
		if (q=='-') sign=true;
	}
	for (d=0; q>=48&&q<=57; (d*=10)+=q^48,q=getchar());
	if (sign) d = -d;
	return true;
}
int main() {
	for (; in(v); puts(c)) {
		in(b), in(s);
		s ? (v|=1<<b) : (v&=~(1<<b));
		c[0] = (v<0)^48;
		for(i=30; i>=0; i--)
			c[31-i] = ((v&1<<i)>>i)^48;
	}
}