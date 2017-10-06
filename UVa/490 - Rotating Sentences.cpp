#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int t=1, i, j, maxl;
char s[200][200];
int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	while (gets(s[t])) t++;
	for (i=1; i<t; i++)
		maxl = max(maxl, strlen(s[i]));
	for (i=0; i<maxl; i++,puts(""))
		for (j=t-1; j>=1; j--)
			putchar(strlen(s[j]) <= i ? ' ' : s[j][i]);
}