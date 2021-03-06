#include <iostream>
#include <string>
using namespace std;

int main() {
	int a;
	string p;
	while (cin >> p) {
		p.erase(p.size()-3, 1);
		a = atoi(p.c_str());
		if (a <= 10000) a = a*9/10 + 800;
		else if (a <= 50000) a = a*8/10;
		else a = a*6/10;
		p.erase(0);
		while (a) {
			p.insert(0, 1, a%10 + '0');
			a /= 10;
		}
		p.insert(p.size()-2, 1, '.');
		cout << '$' << p << endl;
	}
}