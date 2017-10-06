#include <iostream>
#include <stdio.h>
using namespace std;
int n, k, s, ans;

int main() {
	while (~scanf("%d%d",&n,&k)) {
		ans = s = n;
		do {
			ans += s/k;
			s = s/k + s%k;
		} while (s/k);
		printf("%d\n", ans);
	}
}