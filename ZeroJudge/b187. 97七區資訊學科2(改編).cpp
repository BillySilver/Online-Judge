#include <iostream>
using namespace std;
int n;
char a, b;

int main() {
	puts("十六進位表示法  相對應的十進位表示法");
	while (a=getchar(), a!=-1) {
		b = getchar();
		n = a>=65 ? (a^64)+9 : a^48;
		(n*=16) += b>=65 ? (b^64)+9 : b^48;
		printf("      %c%c                 %d\n", a, b, n);
		getchar();
	}
}