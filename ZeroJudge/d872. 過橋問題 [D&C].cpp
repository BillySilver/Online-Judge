#include <iostream>
#include <algorithm>
using namespace std;
int t[100000], sum, n, i;

int main() {
	while (~scanf("%d",&n)) {
		if (!n) {
			puts("0");
			continue;
		}
		for (sum=i=0; i<n; i++)
			scanf("%d",&t[i]);
		sort(t, t+n);
		for (i--; i>=3; i-=2)
			sum += t[i] + min(t[1]+t[1], t[i-1]+t[0]) + t[0];
		if (i==2)
			sum += t[0] + t[1] + t[2];
		else if (i==1)
			sum += t[1];
		else sum += t[0];
		printf("%d\n", sum);
	}
}