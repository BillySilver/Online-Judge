#include <iostream>
char a[33], b[33], c[33];
int now, i;
inline void in(char *d) {
	char q;
	while (q=getchar(), q==10);
	for (i=0; q!=10&&q!=-1; q=getchar()) {
		c[i] = *(d+i++) = q;
	}
}
inline void in2(char *d) {
	char q;
	while (q=getchar(), q==10);
	for (i=0; q!=10&&q!=-1; q=getchar()) {
		c[i] += *(d+i++) = q;
	}
}
int main() {
	while (in(&a[0]), i) {
		in2(&b[0]);
		for (i=31; i>0; i--) {
			c[i] -= 48;
			if (c[i] < 50) continue;
			c[i]-=2;
			c[i-1]++;
		}
		if ((c[0]-=48) > 49) c[0]-=2;
		puts(a);
		puts(b);
		puts("---------------------------------");
		puts(c);
		puts("****End of Data******************");
	}

}