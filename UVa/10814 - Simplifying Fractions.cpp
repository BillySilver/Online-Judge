#include <iostream>
#include <string>
using namespace std;
bool AsmallthanB;

string SIMinus(string a, string b) { //StringIntegerMinus
	int i;
	if (a.size() > b.size())
		b.insert(0, a.size()-b.size(), 0);
	for (i=0; i<a.size(); i++) {
		if (a[i] > b[i]) break;
		if (a[i] == b[i]) continue;
		AsmallthanB = true;
		return a;
	}
	for (i=a.size()-1; i>=0; i--) {
		while (a[i] < b[i]) {
			a[i] += 10;
			a[i-1] -= 1;
		}
		a[i] -= b[i];
	}
	return a;
}

string SIDivide(string a, string b, bool remain) {	//StringIntegerDivide, remain ? 求餘數 : 求商數
	int i, j;
	string m, r;
	if (a.size() < b.size())
		return remain ? a : "0";
	if (a.size() == b.size()) {
		for (i=0; i<a.size(); i++) {
			if (a[i] > b[i]) break;
			if (a[i] == b[i]) continue;
			return remain ? a : "0";
		}
	}
	for (i=a.size()-1; i>=0; i--)
		a[i] -= '0';
	for (i=b.size()-1; i>=0; i--)
		b[i] -= '0';
	m = b;
	m.append(a.size()-b.size(), 0);
	AsmallthanB = false;
	for (j=a.size()+1; !(j==b.size() && AsmallthanB); j--) {
		AsmallthanB = false;
		for (i=0; i<10; i++) {		//a一直減m，直到a<m，此時i=a/m;
			if (m[0] == 0 && m.size() == 1) {
				m[0];
			}
			a = SIMinus(a, m);
			if (AsmallthanB) break;
		}
		if (i==10) i--;				//i是直接減9遍才跳出會變成10
		if (!a[0] && a.size()!=1)	//a前面減到變0時刪掉一個
			a.erase(0, 1);
		r.append(1, i);
		m.erase(m.size()-1);		//m/=10
	}
	if (!remain) {
		for (i=0; i<r.size()-1 && !r[i]; i++);
		r.erase(0, i);				//清除前面所剩的0
		for (i=0; i<r.size(); i++)
			r[i] += '0';
		return r;
	}
	else {
		for (i=0; i<a.size()-1 && !a[i]; i++);
		a.erase(0, i);				//清除前面所剩的0
		for (i=0; i<a.size(); i++)
			a[i] += '0';
		return a;
	}
}

string gcd(string a, string b) {
	a = SIDivide(a, b, 1);
	return  (a != "0") ? gcd(b, a) : b;
}


int main() {
	int n;
	string a, b, d;
	char gar;
	cin >> n;
	while (n--) {
		cin >> a >> gar >> b;
		d = gcd(a, b);
		cout << SIDivide(a, d, 0) << " / " << SIDivide(b, d, 0) << endl;
	}
}