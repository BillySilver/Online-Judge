#include <iostream>
using namespace std;

void honai(int n, int start, int end, int aux) {
	if (n==0) return;
	honai(n-1, start, aux, end);
	printf("Move ring %d from %c to %c\n", n, start+65, end+65);
	honai(n-1, aux, end, start);
}

int main() {
	int i, n;
	while (~scanf("%d",&n))
		honai(n, 0, 2, 1), puts("");
}