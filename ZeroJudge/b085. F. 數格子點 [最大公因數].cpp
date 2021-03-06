#include <iostream>
using namespace std;
int N, x1, y1, x2, y2;

int gcd(int x, int y) {
	return (x%=y) ? gcd(y, x) : y;
}

inline int abs(int x){
	return x>0 ? x : -x;
}

int main() {
	cin >> N;
	while (N--) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1==x2)
			cout << abs(y1-y2)+1 << endl;
		else if (y1==y2)
			cout << abs(x1-x2)+1 << endl;
		else cout << gcd(abs(x1-x2), abs(y1-y2))+1 << endl;
	}
}