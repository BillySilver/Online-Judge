#include <iostream>
int n, m, a, b, start;
char c, g, s[257], i;
struct linked {
	int l;
	char w;
} st[257];

int main() {
	for (scanf("%d",&n); n--; ) {
		scanf("%d%d%c%c%c%d",&m,&a,&g,&c,&g,&b);
		start = a;
		st[a].l = b;
		st[a].w = c;
		for (i=1; i<m; i++) {
			scanf("%d%c%c%c%d",&a,&g,&c,&g,&b);
			st[a].l = b;
			st[a].w = c;
		}
		for(i=0; i<m; i++) {
			s[i] = st[start].w;
			start = st[start].l;
		}
		s[m] = 0;
		puts(s);
	}
}