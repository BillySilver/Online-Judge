#include <iostream>
int n, sum, mx, a, b, c, now;
char s[21], nm[21], F, W;

int main() {
	for (scanf("%d",&n); n--; sum += now) {
		now = !scanf("%s%d%d %c %c%d", &s, &a, &b, &F, &W, &c);
		if (a > 90) now += 2000;
		if (a > 85 && b > 80) now += 4000;
		if (a > 85 && W == 'Y') now += 1000;
		if (a > 80 && c) now += 8000;
		if (b > 80 && F == 'Y') now += 850;
		if (now > mx&&(mx=now)) strcpy(nm, s);
	}
	puts(nm);
	printf("%d\n%d", mx, sum);
}