#include <iostream>
using namespace std;
int a[10000], n, i;

int main () {
	while (cin >> n) {
		for (i=n; i>=0; i--)
			scanf("%d", &a[i]);
		if (a[n] < 0) printf("-");
		a[n] = abs(a[n]);
		if (a[n] != 1) printf("%d",a[n]);
		printf("x^%d", n);
		for (i=n-1; i>1; i--) {
			if (!a[i]) continue;
			printf("%s", ( (a[i]>0) ? "+" : "-" ));
			a[i] = abs(a[i]);
			if (a[i] != 1) printf("%d", a[i]);
			printf("x^%d", i);
		}
		if (a[1]) {
			printf("%s", ((a[1]>0) ? "+" : "-" ));
			a[1] = abs(a[1]);
			if (a[1] != 1) printf("%d", a[1]);
			printf("x");
		}
		if (a[0])
			printf("%s%d", ( (a[0]>0) ? "+" : "-" ) , abs(a[0]) );
		printf ("\n");
	}
}