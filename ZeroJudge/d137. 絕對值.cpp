#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int a, b, i, j;
string s;

int main() {
	while (cin >> s) {
		for (i=0; s[i]<48 || s[i]>57; i++)
			if (s[i] == 'i') break;
		for (a=0; i<s.size(); i++) {
			if (isdigit(s[i]))
				a = a*10 + s[i]-48;
			else if (s[i]=='i') {
				if (!a) a = 1;
				i++;
				break;
			}
			else break;
		}
		for (b=0; i<s.size(); i++) {
			if (isdigit(s[i]))
				b = b*10 + s[i]-48;
			else if (!b && s[i]=='i') b=1;
		}
		printf("%.3lf\n", sqrt((double)a*a+b*b) );
	}
}