#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, i;
	string s, end;
	while (cin >> n) {
		s.assign(n, '0');
		end.assign(n, '1');
		cout << s << endl;
		while (s != end) {
			s[n-1] += 1;
			for (i=n-1; i>=0; i--) {
				if (s[i] == '2') {
					s[i] = '0';
					s[i-1]++;
				}
				else break;
			}
			cout << s << endl;
		}
	}
}