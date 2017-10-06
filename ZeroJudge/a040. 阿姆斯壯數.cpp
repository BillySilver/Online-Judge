#include <iostream>
#include <cmath>
using namespace std;
int n, m, i, j, a, b, di[7], lp, sum, asas;
bool ans;

int main () {
	while (cin >> n >> m) {
		ans = false;
		for (a=n,i=0; a; i++) {
			a /= 10;
		}
		for (lp=pow((double)10,i); n<=m; n++) {
			if (n == lp) {
				i++;
				lp *= 10;
			}
			for (a=n,sum=j=0; a; j++) {
				asas = a%10;
				sum += pow((double)asas,i);
				a /= 10;
			}
			if (sum == n) {
				cout << n << ' ';
				ans = true;
			}
		}
		if (!ans) cout << "none\n";
		else cout << endl;
	}
}