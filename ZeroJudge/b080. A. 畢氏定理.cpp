#include <iostream>
#include <cmath>
int a, b;
double i, j;

int main() {
	while (scanf("%d%d",&a,&b), a) {
		if (a < b) a^=b^=a^=b;
		a *= a, b *= b;
		i = sqrt((double)a+b);
		j = sqrt((double)a-b);
		if (floor(i) == ceil(i)) {
			printf("%.0f\n", i);
			if (floor(j) == ceil(j))
				printf("%.0f\n", j);
		}
		else if (floor(j) == ceil(j))
			printf("%.0f\n", j);
		else puts("Wrong");
	}
}