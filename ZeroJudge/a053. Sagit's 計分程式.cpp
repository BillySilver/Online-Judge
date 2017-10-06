#include <iostream>
using namespace std;
int n;

int main() {
	while (~scanf("%d", &n)) {
		if (n<=10) n *= 6;
		else if (n<=20) n = 60 + (n-10)*2;
		else if (n<=40) n += 60;
		else n = 100;
		printf("%d\n", n);
	}
}