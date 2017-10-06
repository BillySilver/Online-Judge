#include <iostream>
#include <string>
using namespace std;
int f[10001] = {1, 1};

int fa(int a) {
	if (!f[a]) {
		return f[a] = ( fa(a-1) + fa(a-2) ) % 2012;
	}
	else return f[a];
}

int main() {
	int n;
	while (cin >> n) {
		cout << fa(n) << endl;
	}
}