#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int v[]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2}, last, i, tmp;
char s[25], ans[4];

int main() {
	puts("         NAME                     SOUNDEX CODE");
	while (~scanf("%s", s)) {
		printf("         %-25s%c", s, s[0]);
		memset(ans, 0, sizeof(ans));
		last = v[s[0]-'A'];
		for (i=1; s[i]&&strlen(ans)<3; i++) {
			if ((tmp=v[s[i]-'A']) != last && tmp)
				ans[strlen(ans)] = tmp|48;
			last = tmp;
		}
		for (; strlen(ans)<3; ans[strlen(ans)]='0');
		puts(ans);
	}
	puts("                   END OF OUTPUT");
}