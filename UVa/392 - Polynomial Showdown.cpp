#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int a[9], i, j, tail;
bool sign;
char s[90];

void att(char q) {
	s[tail++] = q;
}

void ita(int v) {
	for (j=100; j>v&&j!=1; j/=10);
	do {
		att(v/j | 48);
		v %= j, j /= 10;
	} while (j);
}

int main() {
	while (~scanf("%d", &a[8])) {
		for (i=7; ~i; i--)
			scanf("%d", &a[i]);
		tail = 0;
		for (i=8; ~i; i--) {
			if (!a[i]) continue;
			sign = a[i] < 0;
			a[i] = abs(a[i]);
			if (!tail) {
				if (sign) att('-');
			}
			else
				att(' '), att(sign ? '-' : '+'), att(' ');
			if (a[i] != 1 || !i) ita(a[i]);
			if (i > 0) att('x');
			if (i > 1) att('^'), att(i|48);
		}
		if (!tail) att('0');
		s[tail] = 0;
		puts(s);
	}
}