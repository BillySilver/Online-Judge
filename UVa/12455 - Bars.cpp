#include <stdio.h>
#include <string.h>
int t, i, n, p, s;
bool can[1001];

int main() {
	for (scanf("%d",&t); t--; puts(can[n] ? "YES" : "NO")) {
		memset(can, 0, sizeof(can));
		can[0] = true;
		for (scanf("%d %d", &n, &p); p--; ) {
			scanf("%d", &s);
			for (i=n; i>=s; i--)
				if (can[i-s])
					can[i] = true;
		}
	}
}
