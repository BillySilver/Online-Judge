#include <iostream>
int i;
unsigned long long n = 2046;

int main() {
	while (~scanf("%d",&i)) {
		if (i<10)
			printf("%llu\n", n>>9-i&-2);
		else
			printf("%llu\n", n<<i-9);
	}
}