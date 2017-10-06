#include <stdio.h>
#include <string.h>
int i, t;
char s[102];

int main() {
	while (scanf("%s", s)) {
		if (strlen(s)==1) {
			if (s[0] == '0') break;
			puts("0");
			continue;
		}
		for (t=i=strlen(s); i; i--)
			s[i-1]^=48;
		for (i=t-1; i>=2; i--) {
			s[i-1] -= s[i]*5%10;
			if (s[i-1] < 0)
				s[i-2]--, s[i-1]+=10;
			s[i-2] -= s[i]*5/10;
			if (s[i-2]<0 && i>2)
				s[i-3]--, s[i-2]+=10;
		}
		printf("%d\n", !((s[0]*10+s[1])%17));
	}
}