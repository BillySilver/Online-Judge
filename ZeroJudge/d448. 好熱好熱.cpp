#include <iostream>
using namespace std;

int main() {
	double t1, t2, t3, x1, x3, x2;
	while (cin >> t1 >> t2 >> t3 >> x1 >> x3) {
		x2 = x1 - (x1-x3) / (t1-t3) * (t1 - t2);
		printf("%.6f\n", x2);
	}
}