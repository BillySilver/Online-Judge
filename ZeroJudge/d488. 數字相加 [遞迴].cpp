#include <iostream>
using namespace std;
int n, a[20000], i;

void dfs (int i, int sum) {
	if (i!=n) {
		cout << " + " << a[i];
		dfs(i+1, sum+a[i]);
	}
	else cout << " = " << sum << endl;
}

int main() {
	while (cin >> n, n) {
		for (i=0; i<n; i++)
			cin >> a[i];
		cout << a[0];
		dfs(1, a[0]);
	}
}