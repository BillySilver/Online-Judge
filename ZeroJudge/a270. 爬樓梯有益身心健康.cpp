#include <iostream>
#include <stdio.h>
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
using namespace std;
int n, t[6], i, f1, f2;
bool ans;
int main() {
	while (~scanf("%d", &n)) {
		for (i=2; i<=5; i++)
			scanf("%d", &f1), t[i] = t[i-1] + f1;
		scanf("%d", &f1);
		for (ans=i=1; i<8; i++) {
			scanf("%d", &f2);
			if (ans && n < t[MAX(f1, f2)] - t[MIN(f1, f2)] )
				ans = false;
			f1 = f2;
		}
		puts(ans ? "yes" : "no");
	}
}