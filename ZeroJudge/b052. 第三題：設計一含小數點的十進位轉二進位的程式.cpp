#include <iostream>
#include <string>
using namespace std;
int inte, deci, i, e, e_deci;
char gar;
string s;

inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (e=d=0; isdigit(q); q=getchar(), e++)
		(d*=10) += q^48;
}

int main() {
	while (cin >> inte >> gar) {
		in(deci);
		for (s="",i=0; 1<<i<=inte; i++)
			s.insert(0, 1, (1<<i&inte)>>i|48);
		for (e_deci=1; e--; e_deci*=10);
		for (s+='.',i=0; deci%=e_deci; i++)
			s.append(1, (deci*=2)/e_deci+48);
		printf("%s\n", s.c_str());
	}
}