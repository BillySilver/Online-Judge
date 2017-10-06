#include <iostream>
#include <algorithm>
using namespace std;
int n, s[1000], i, sum;

int main() {
	while (scanf("%d",&n), n) {
		for (sum=i=0; i<n; i++) {
			scanf("%d",&s[i]);
			sum += s[i];
		}
		sort(s, s+n);
		for (i=0; s[i]*n<sum; i++);
		printf("%d\n", i);
	}
}