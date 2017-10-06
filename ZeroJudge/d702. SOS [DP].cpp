#include <iostream>
#include <string>
using namespace std;
int i;
string dp[1001]={"0", "1", "1"};
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar())&&q!=-1);
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
string SIPlus(string a, string b) { //StringIntegerPlus
	int i;
	if (a.size() > b.size())
		b.insert(0, a.size()-b.size(), 48); //從第0位開始 插入長度差個數的'0'
	else if (a.size() < b.size())
		a.insert(0, b.size()-a.size(), 48);
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
	for (i=3; i<1001; i++)
		dp[i] = SIPlus(dp[i-2], dp[i-3]);
	while (in(i), i) 
		puts(dp[i].c_str());
}