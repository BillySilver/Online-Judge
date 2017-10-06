#include <iostream>
#include <stdio.h>
int i;
char s[100000];
bool d;

int main() {
	while (gets(s)) {
		for (i=0; s[i]; i++) {
			if (s[i] == '\"')
				printf("%s", (d=!d) ? "``" : "\'\'");
			else putchar(s[i]);
		}
		puts("");
	}
}