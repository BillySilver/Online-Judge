#include <stdio.h>
unsigned long long gene[81], i;	//0: ¤½, 1: ¥À

int main() {
	gene[0] = gene[1] = 1;
	for (i=2; i<81; i++)
		gene[i] = gene[i-1] + gene[i-2];
	while (scanf("%llu",&i), i)
		printf("%llu\n", gene[i]);
}