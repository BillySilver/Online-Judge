#include <iostream>
using namespace std;
int n, a, b;

int gcd(int x, int y) {
	return (x%=y) ? gcd(y, x) : y;
}

int main() {
	while (cin >> n) {
		cin >> a;
		n--;
		while (n--) {
			cin >> b;
			a = gcd(a,b);
		}
		cout << a << endl;
	}
}