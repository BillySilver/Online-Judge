#include <iostream>
int acsii, i;
char s[10000];

inline void in(int &d) {
	char q;
	while (q=getchar(), q=='_'||q=='|'||q==10)
		if (q==-1) break;
	for (d=0; q==' '||q=='o'||q=='.'; q=getchar()) {
		if (q=='.') continue;
		(d <<= 1) ^= q=='o' ? 1 : 0;
	}
}

int main() {
	while(in(acsii), acsii)
		s[i++] = acsii;
	puts(s);
}