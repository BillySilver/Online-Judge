#include <iostream>
using namespace std;
int n, k, mx, v[1000], c[1000];

inline void dfs(int i, int all, int sum) {
	if (all > 100) return;
	if (i==k) {
		mx = max(mx, sum);
		return;
	}
	dfs(i+1, all+v[i], sum+c[i]);
	dfs(i+1, all, sum);
}

int main() {
	while(cin >> n) {
		for (mx=k=0; k<n; k++)
			cin >> v[k] >> c[k];
		dfs(0, 0, 0);
		printf("%d\n", mx);
	}
}