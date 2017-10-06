#include <iostream>
#include <string>
using namespace std;
string f[5001] = {"0","1","1"};
bool done[5001] = {true, true, true};

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

int main() {
	int a, i;
	for (i=3; i<5001; i++)
		f[i] = SIPlus(f[i-1], f[i-2]);
	while (scanf("%d",&a)==1)
		printf("The Fibonacci number for %d is %s\n", a, f[a].c_str());
}