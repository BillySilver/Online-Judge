#include <iostream>
#include <string>
using namespace std;
int i;
string s, a;

string AND(string s, string f) {
	s[0] = (s[0]-48&&f[0]-48) ? '1' : '0';
	s[1] = (s[1]-48&&f[1]-48) ? '1' : '0';
	s[2] = (s[2]-48&&f[2]-48) ? '1' : '0';
	s[3] = (s[3]-48&&f[3]-48) ? '1' : '0';
	s[4] = (s[4]-48&&f[4]-48) ? '1' : '0';
	return s;
}

string OR(string s, string f) {
	s[0] = (s[0]-48||f[0]-48) ? '1' : '0';
	s[1] = (s[1]-48||f[1]-48) ? '1' : '0';
	s[2] = (s[2]-48||f[2]-48) ? '1' : '0';
	s[3] = (s[3]-48||f[3]-48) ? '1' : '0';
	s[4] = (s[4]-48||f[4]-48) ? '1' : '0';
	return s;
}

int main() {
	while(getline(cin, s), s!="") {
		a.assign(s, 0, 5);
		for (i=6; i<s.size(); i++) {
			if (s[i]==' ') continue;
			if (s[i]=='a') {
				s.replace(i-1, 5, "&&");
				a = AND(a, s.substr(++i, 5));
			}
			else if (s[i]=='o') {
				s.replace(i-1, 4, "||");
				a = OR(a, s.substr(++i, 5));
			}
		}
		printf("%s= %s\n", s.c_str(), a.c_str());
	}
}