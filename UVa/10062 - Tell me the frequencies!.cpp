#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int i, cas, ascii[255], sp[255];
char s[1001];

bool pre(int a, int b) {
	return ascii[a] == ascii[b] ? a > b : ascii[a] < ascii[b];
}

int main() {
	while (gets(s)) {
		if (cas++) puts("");
		for (i=0; i<255; i++) sp[i] = i, ascii[i] = 0;
		for (i=0; s[i]; i++) ascii[s[i]]++;
		sort (sp, sp+255, pre);
		for (i=0; i<255; i++)
			if (ascii[sp[i]])
				printf("%d %d\n", sp[i], ascii[sp[i]]);
	}
}