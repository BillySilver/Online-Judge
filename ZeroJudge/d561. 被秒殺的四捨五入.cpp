#include <iostream>
#include <string>
using namespace std;
int n, i;
string s;

int main() {	
	while (cin >> s) {
		n = s.find('.');
		s.append(2, '0');
		if (s[n+3]>=53) s[n+2]++;
		if (s[n+2]>=58) s[n+2]-=10, s[n+1]++;
		if (s[n+1]>=58) s[n+1]-=10, s[n-1]++;
		s.erase(n+3);
		if (s=="-0.00") s.erase(0, 1);
		printf("%s\n", s.c_str());
	}		
}