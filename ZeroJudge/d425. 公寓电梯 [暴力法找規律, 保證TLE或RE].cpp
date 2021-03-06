#include <iostream>
using namespace std;
int k, dis, diss[100], mn;

void dfs(int top, int f) {
	if (f>top) return;
	dis = (f-1)*(f-2)/2 + (top-f+1)*(top-f);
	diss[f] = dis;
	mn = min(mn, dis);
	dfs(top, f+1);
}

int main() {
	while (cin >> k) {
		mn = 2147483647;
		dfs(k, 2);
		for (k=0; k<100; k++)
			if (diss[k]==mn) printf("%d ", k);
		printf("\n");
	}
}
