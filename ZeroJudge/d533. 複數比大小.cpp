#include <iostream>
using namespace std;
int n;
double a, b, c, d;

int main() {
	cin >> n;
	while (n--) {
		cin >> a >> b >> c >> d;
		if (a == c && b == d) cout << "=\n";
		else if (b==0 && d == 0) {
			if (a > c) cout << ">\n";
			if (a < c) cout << "<\n";
		}
		else cout << "No\n";
	}
}