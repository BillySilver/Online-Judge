#include <iostream>
#include <string>
using namespace std;
int n, m, i, a, b;
string s;

inline void in(int &d) {
	char ch;
	while (!isdigit(ch=getchar()));
	d = 0;
	do (d*=10) += ch^48;
	while (isdigit(ch=getchar()));
}

inline void Intin (int &d) {
    char ch;
    while (!isdigit(ch=getchar()));
    do d = ch^48;
    while (isdigit(ch=getchar()));
}

int main() {
	in(n);
	while (n--) {
		in(m);
		s = "";
		for (i=0; i<m; i++) {
			Intin(a) , Intin(b);
			s+=char(a+b+48);
		}
		for (i=m-1; i>0; i--) {
			if (s[i] > 57) {
				s[i-1]++;
				s[i]-=10;
			}
		}
		if (s[0] > 57) {
			s[0]-=10;
			s.insert(0, 1, '1');
		}
		printf("%s\n\n", s.c_str());
	}
}