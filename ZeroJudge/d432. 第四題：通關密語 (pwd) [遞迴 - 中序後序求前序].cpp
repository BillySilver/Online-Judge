#include <iostream>
char in[61], pos[61], as[255], i;

void pre(int il, int ir, int pl, int pr) {
	if (il > ir) return;
	putchar(pos[pr]);
	pre(il, as[pos[pr]]-1, pl, pl+as[pos[pr]]-il-1);
	pre(as[pos[pr]]+1, ir, pl+as[pos[pr]]-il, pr-1);
}

int main() {
	for (; gets(in); pre(0, i-1, 0, i-1), puts(""))		
		for (gets(pos), i=0; in[i]; as[in[i]]=i++);
}