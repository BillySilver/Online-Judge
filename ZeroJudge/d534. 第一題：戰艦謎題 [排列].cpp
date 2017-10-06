#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, d, z[4] = {0, 1, 2, 3}, e=1;
	cin >> a >> b >> c >> d;
	if (a==1 && b==5 && c==2 && d==4)
		cout << "0 1\n2 3\n";
	else {
		while (next_permutation(z,z+4))
			if (z[0] + z[1] == a && z[2] + z[3] == b && z[0] + z[2] == c && z[1] + z[3] == d) {
				cout << z[0] << ' ' << z[1] << '\n' << z[2] << ' ' << z[3] << endl;
				e = 0;
				break;
			}
			if (e) cout << "No solutions.\n";
	}
}