#include <iostream>
#include <iomanip>
using namespace std;
float x, y, a1, a2, b1, b2;

int main() {
	while (cin >> a1) {
		cin >> a2 >> b1 >> b2;
		x = (b2-b1)/(a1-a2);
		y = a1*x+b1;
		if (!x) x = 0;
		if (!y) y = 0;
		cout << fixed << setprecision(2) << x << endl << y << endl;
	}
}