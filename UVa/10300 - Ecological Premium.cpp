#include <iostream>  
using namespace std;   
  
int main () {  
	long long n, f, a, b, c, d;
	cin >> n;
	while (n--) {
		cin >> f;
		d = 0;
		while (f--) {
			cin >> a >> b >> c;
			d = d+a*c;
		}
		cout << d << endl;
	}
}