#include<string>
#include<iostream>
using namespace std;

int main() {
	int i;
	string s, kb = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./  ";
	while (getline(cin,s)) {
		i = 0;
		while (i < s.size()){
			s[i] = kb[ kb.rfind(s[i]) - 1 ];
			i++;
		}
		cout << s << endl;
	}
}