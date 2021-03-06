#include <iostream>
using namespace std;
int Prime[78498], now, i, j, n, a[500000], e[500000];
bool Prime_Table[1000001] = {true, true};

int main() {
	for (i=2; i<1000001; i++) {
		if (Prime_Table[i]) continue;
		Prime[now++] = i;
		for (j=i*2; j<1000001; j+=i) 
			Prime_Table[j] = true;
	}
	while (cin >> n) {
		memset(a, 0, sizeof(a));
		memset(e, 0, sizeof(e));
		for (j=i=0; i<now&&n; i++) {
			if (n%Prime[i]) continue;
			for (a[j++]=Prime[i]; !(n%Prime[i]); n/=Prime[i])
				e[j-1]++;
		}
		for (i=0; i<j-1; i++)
			if (e[i] > 1)
				printf("%d^%d * ", a[i], e[i]);
			else
				printf("%d * ", a[i]);
		if (e[i] > 1)
			printf("%d^%d\n", a[i], e[i]);
		else
			printf("%d\n", a[i]);
	}
}