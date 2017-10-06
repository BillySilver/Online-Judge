#include <iostream>
#include <string>
using namespace std;

inline void Linein(string &d) {
    char ch;
    while (ch=getchar(), ch==10);
	d = "";
	if (ch==-1) return;
	do {
		if (ch<0) {
			d += ch;
			d += (ch=getchar());
		}
	}
	while (ch=getchar(), ch!=10);
}

int main() {
	int n, i;
	string s;
	while (Linein(s), !s.empty()) {
		printf("%s\n", s.c_str());
	}
}