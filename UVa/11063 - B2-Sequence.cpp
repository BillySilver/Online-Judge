#include <iostream>
#include <algorithm>
using namespace std;
int b[100], sum[6000], now, n, i, j, t;
bool y;

int main() {
	while (~scanf("%d",&n)) {
		y = true;
		for (i=0; i<n; i++)
			scanf("%d",&b[i]);
		if (b[0] < 1) y = false;
		for (i=1; i<n; i++)
			if (b[i-1] >= b[i])
				y = false;
		for (now=i=0; i<n; i++)
			for (j=i; j<n; j++)
				sum[now++] = b[i] + b[j];
		sort(sum, sum+now);
		for (i=1; i<now-1; i++)
			if (sum[i-1] == sum[i])
				y = false;
		printf("Case #%d: It is%s a B2-Sequence.\n\n", ++t, y ? "" : " not");
	}
}