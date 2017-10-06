#include <iostream>  
#include <math.h>  
using namespace std;   

int main () {
	unsigned int n, a;
	double b;
	while (cin >> n, n) {
		a = sqrt(double(n));
		b = sqrt(double(n));
		if (n/a == b) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}