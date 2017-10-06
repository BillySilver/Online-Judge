#include <stdio.h>
int mx, now, i;
char s[1000001];

int main() {
	while (gets(s)) {
		for (i=1,mx=now=s[0]==' '; s[i]; i++) {
			if (s[i] == ' ') {
				now++;
				continue;
			}
			if (s[i-1] != ' ')
				continue;
			mx = mx > now ? mx : now;
			now = 0;
		}
		mx--;
		for (i=0; mx; mx>>=1,i++);
		printf("%d\n", i);
	}
}
