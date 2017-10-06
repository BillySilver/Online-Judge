#include <iostream>
#include <cmath>
using namespace std;
int n, m, i, a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634, 8208, 9474, 54748, 92727, 93084, 548834};
bool lp;

int main () {
	while (cin >> n >> m) {
		for (lp=i=0; i<20; i++) {
			if (a[i] >= n && a[i] <= m) {
				cout << a[i] << ' ';
				lp = true;
			}
		}
		if (!lp) cout << "none";
		cout << endl;
	}
}