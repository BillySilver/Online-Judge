#include <iostream>
#include <stdio.h>
using namespace std;
int n, m, i, a, b;
char s[1000002];

int main() {
	for (scanf("%d",&n); n--; ) {
		scanf("%d", &m);
		for (s[0]=s[m+1]=0,i=1; i<=m; i++) {
			scanf("%d%d", &a, &b);
			s[i] = a + b;
		}
		for (i=m; i; s[i]^=48,i--)
			if (s[i] > 9)
				s[i] -= 10, s[i-1]++;
		if (s[0]) s[0]^=48;
		puts(s[0]?s:s+1);
		if (n) puts("");
	}
}