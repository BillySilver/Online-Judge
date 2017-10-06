#include <iostream>
using namespace std;
int a[5];
bool use[5], ans;

void dfs (long long sum) {
	int i;
	if (!ans) {
		for (i=0; i<5; i++) {
			if (use[i]) continue;
			use[i] = true;
			dfs(sum+a[i]);
			dfs(sum-a[i]);
			dfs(sum*a[i]);
			use[i] = false;
		}
		if (use[0] == true && use[1] == true && use[2] == true && use[3] == true && use[4] == true && sum == 23)
			ans = true;
	}
}
int main() {
	int i;
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4], a[0]+a[1]+a[2]+a[3]+a[4]) {
		for (ans=i=0; i<5; i++) {
			use[i] = true;
			dfs(a[i]);
			use[i] = false;
		}
		if (ans) cout << "Possible\n";
		else cout << "Impossible\n";
	}
}