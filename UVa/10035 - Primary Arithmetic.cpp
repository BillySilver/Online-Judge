#include <iostream>
using namespace std;
int n, a[10], b[10], i, j, k, x, y, carry, c;

int main() {
	while (cin >> x >> y, x+y) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (i=0; x; i++) {
			a[i] = x%10;
			x /= 10;
		}
		for (j=0; y; j++) {
			b[j] = y%10;
			y /= 10;
		}
		for (c=carry=k=0; k<=i || k<= j; k++) {
			if (a[k] + b[k] + c > 9) {
				carry++;
				c = 1;
			}
			else c = 0;
		}
		if (carry) printf("%d carry operation%s\n", carry, carry==1?".":"s.");
		else printf("No carry operation.\n");
	}
}