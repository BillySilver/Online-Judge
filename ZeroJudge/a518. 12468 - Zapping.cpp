#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int a, b;

int main() {
	while (scanf("%d%d",&a,&b), ~a)
		printf("%d\n", std::min(abs(a-b), 100-abs(a-b)));
}