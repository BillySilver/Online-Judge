#include <iostream>
long long a, n, i;
char s[100000];

inline long long exp(long long x, long long y) {
	if (!y) return 1;
	long long k = exp(x, y/2);
	k *= k;
	if (y&1) k *= x;
	return k;
}

int main() {
	while (gets(s), !(s[0]==48&&s[1]==32&&s[2]==48&&!s[3])) {
		a = s[0]=='-' ? 0 : s[0]^48;
		for (i=1; s[i]!=32; i++)
			(a*=10) += s[i]^48;
		if (s[0]=='-') a = -a;
		if (!a||a==1) putchar(a|48), putchar(10);
		else if (!~a){
			for (; s[i]; i++);
			puts( s[i-1]&1 ? "-1" : "1");
		}
		else {
			for (n=0; s[++i]; (n*=10) += s[i]^48);
			if (!n) putchar(49), putchar(10);
			else printf("%lld\n", exp(a, n));
		}
	}
	puts("All Over.");
}