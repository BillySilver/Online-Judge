#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int	t, n, i, p[20000], s;
	for (cin >> t; t; t--) {
		cin >> n;
		s = 0;
		for (i=0; i<n; i++)
			cin >> p[i];
		sort (p, p+i);
		for (i-=3; i>=0; i-=3)
			s += p[i];
		cout << s << endl;
	}
}