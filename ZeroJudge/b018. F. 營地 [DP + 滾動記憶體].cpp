#include <iostream>
using namespace std;
int f[5001][2], i, j, l, w, b, mx;

int main() {
	for (; scanf("%d%d",&l,&w), l+w; printf("%d\n", mx*mx)) {
		memset(f, 0, sizeof(f));
		for (mx=b=j=0; j<l; b=!b, j++)
			for (i=1; i<=w; i++) {
				scanf("%d",&f[i][b]);
				if (f[i][b] != 2) mx = max( f[i][b] = min(min(f[i-1][b], f[i][!b]) , f[i-1][!b]) + 1 , mx );
				else f[i][0] = 0;
			}
	}
}