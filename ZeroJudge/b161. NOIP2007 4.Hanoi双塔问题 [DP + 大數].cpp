#include <iostream>
#include <string>
using namespace std;
int n, k;
string e[201]={"","4"}, ans;
string SIPlus(string a, string b) { //StringIntegerPlus
	int i;
	if (a.size() > b.size())
		b.insert(0, a.size()-b.size(), '0'); //從第0位開始 插入長度差個數的'0'
	else if (a.size() < b.size())
		a.insert(0, b.size()-a.size(), '0');
	for (i=a.size()-1; i>0; i--) {
		a[i] = a[i] - '0' + b[i] - '0';
		a[i-1] += a[i] / 10;
		a[i] %= 10;
	}
	a[i] = a[i] - '0' + b[i] - '0';
	if (a[i]/10) {
		a.insert(0, 1, a[0]/10);
		a[i+1] %= 10;
	}
	for (i=0; i<a.size(); i++)
		a[i] += '0';
	return a;
}

inline void in(int &d) {
	char q;
	while (q=getchar(), q>57||q<48)
		if (q==-1) break;
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}

int main() {
	for (k=2; k<201; k++)
		e[k] = SIPlus(e[k-1], e[k-1]);
	while (in(n), n) {
		ans = e[n];
		ans[ans.size()-1]-=2;
		puts(ans.c_str());
	}
}