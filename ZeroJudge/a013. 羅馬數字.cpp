#include <iostream>
#include <string>
using namespace std;
int num[255], i, j, an, bn;
string a, b, ans;

int rton(string s) {
	for (j=i=0; i<s.size()-1; i++)
		j += (num[s[i]] < num[s[i+1]]) ? -num[s[i]] : num[s[i]];
	return j += num[s[i]];
}

void ntor(int n) {
	for (ans = ""; n >= 1000; n-=1000)
		ans += "M";
	if (n/100 == 9) {
		ans += "CM";
		n -= 900;
	}
	else {
		if (n/100 >= 5) {
			ans += "D";
			n -= 500;
		}
		for (; n >= 100; n-=100)
			ans += "C";
	}
	if (n/10 == 9) {
		ans += "XC";
		n -= 90;
	}
	else {
		if (n/10 >= 5) {
			ans += "L";
			n -= 50;
		}
		for (; n >= 10; n-=10)
			ans += "X";
	}
	if (n == 9) {
		ans += "IX";
		n -= 9;
	}
	else {
		if (n >= 5) {
			ans += "V";
			n -= 5;
		}
		for (; n >= 1; n-=1)
			ans += "I";
	}
	if (ans == "") ans = "ZERO";
}

int main() {
	num['I'] = 1;
	num['V'] = 5;
	num['X'] = 10;
	num['L'] = 50;
	num['C'] = 100;
	num['D'] = 500;
	num['M'] = 1000;
	while (cin >> a, a!="#") {
		cin >> b;
		an = rton(a);
		bn = rton(b);
		an = abs(an-bn);
		ntor(an);
		cout << ans << endl;
	}
}