#include <iostream>
#include <stdio.h>
using namespace std;
int t, n, now, bh, i, ans;
char s[27];

int main() {
	for (scanf("%d",&t); t--; ) {
		now = (1 << 26) - 1;
		for (ans=!scanf("%d", &n); n--; ) {
			scanf("%s", s);
			for (bh=i=0; s[i]; i++)
				bh |= 1 << (s[i]-'a');
			now &= bh;
			if (!now) now = bh, ans++;
		}
		printf("%d\n", ans);
	}
}