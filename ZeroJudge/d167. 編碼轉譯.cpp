#include <iostream>
int acsii, i, now;
char q;
char s[100000];

inline void in(int &d) {
	char q;
	while (q=getchar(), q=='_'||q=='|'||q==10)
		if (q==-1) break;
	for (d=0; q=='o'||q==' '||q=='.'; q=getchar()) {
		if (q=='.') continue;
		(d <<= 1) ^= q=='o' ? 1 : 0;
	}
}

int main() {
	while(q=getchar(), q!=-1) {
		now = 0;
		for (i=0; i<11; i++)
			s[now++] = '_';		
		for (s[now++]=10; q!=10; q=getchar()) {
			s[now++] = '|';
			for (i=7; i>2; i--)
				s[now++] = (q & 1<<i) ? 'o' : ' ';
			for (s[now++]='.'; i>=0; i--)
				s[now++] = (q & 1<<i) ? 'o' : ' ';
			s[now++] = '|';
			s[now++] = 10;
		}
		s[now++] = '|';
		for (i=7; i>2; i--)
			s[now++] = (q & 1<<i) ? 'o' : ' ';
		for (s[now++]='.'; i>=0; i--)
			s[now++] = (q & 1<<i) ? 'o' : ' ';
		s[now++] = '|';
		s[now++] = 10;
		for (i=0; i<11; i++)
			s[now++] = '_';
		s[now++] = 0;
		puts(s);
	}
}