#include <iostream>
#include <string>
using namespace std;
bool Multiply;

string SIPlus(string a, string b) { //StringIntegerPlus
	int i;
	if (a.size() > b.size())
		b.insert(0, a.size()-b.size(), 0); //從第0位開始 插入長度差個數的0
	else if (a.size() < b.size())
		a.insert(0, b.size()-a.size(), 0);
	for (i=a.size()-1; i>0; i--) {
		a[i] = a[i] + b[i];
		a[i-1] += a[i] / 10;
		a[i] %= 10;
	}
	a[i] = a[i] + b[i];
	if (a[i]/10) {
		a.insert(0, 1, a[0]/10);
		a[i+1] %= 10;
	}
	return a;
}

string SIMultiply(string a, string b) { //StringIntegerMultiply
	int i;
	string m[10], r;
	for (i=a.size()-1; i>=0; i--)
		a[i]^=48;
	for (i=b.size()-1; i>=0; i--)
		b[i]^=48;
	m[0].insert(0, 1, 0);
	m[1].assign(a.begin(), a.end() );
	for (i=2; i<10; i++)
		m[i] += SIPlus(m[i-1], a);
	for (i=b.size()-1; i>=0; i--){
		a = m[b[i]];
		a.append(b.size()-1-i, 0);
		r = SIPlus(a, r);
	}
	for (i=0; i<r.size(); i++)
		r[i]|=48;
	return r;
}

int n, c;
bool done[1001] = {true};
string prob[1001] = {"1"};

string factorial(int a) {
	if (!done[a]) {
		int b = a;
		string num, now;
		while (a) {
			num.insert(0, 1, (a%10)^48);
			a /= 10;
		}
		done[b] = true;
		// now = SIMultiply(factorial(b-1), num);
		// prob[b].assign(now.begin(), now.end() );
		return prob[b] = SIMultiply(factorial(b-1), num);
	}
	return prob[a];
}

int main() {
	int i, sum;
	string s;
	while (cin >> n) {
		s = factorial(n);
		for (sum=i=0; i<s.size(); i++)
			sum += s[i]^48;
		cout << sum << endl;
	}
}
