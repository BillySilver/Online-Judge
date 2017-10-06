#include <iostream>
#include <stdio.h>
using namespace std;
int t, i, mx, cas;

struct data {
	int v;
	char s[100];
} d[10];

int main() {
	for (scanf("%d",&t); t--; ) {
		for (mx=i=0; i<10; i++)
			scanf("%s %d", d[i].s, &d[i].v), mx = max(mx, d[i].v);
		printf("Case #%d:\n", ++cas);
		for (i=0; i<10; i++)
			if (d[i].v == mx) puts(d[i].s);
	}
}