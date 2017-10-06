#include <stdio.h>
#include <string.h>
int T, ascii[255], i, j;
char s[2002];
bool prime[2002]={1,1}, ok;

int main() {
	for (i=2; i<2002; i++)
		if (!prime[i])
			for (j=i*i; j<2002; j+=i)
				prime[j] = true;
	for (i=!scanf("%d",&T); T--; ) {
		scanf("%s", s);
		memset(ascii, 0, sizeof(ascii));
		for (j=0; j<strlen(s); j++)
			ascii[s[j]]++;
		ok = !printf("Case %d: ", ++i);
		for (j=0; j<255; j++)
			if (!prime[ascii[j]])
				ok = putchar(j);
		puts(ok ? "" : "empty");
	}
}