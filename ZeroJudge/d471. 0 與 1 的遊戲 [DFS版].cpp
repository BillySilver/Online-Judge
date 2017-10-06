#include <iostream>
#include <string>
using namespace std;
int n, i;
string s;

void dfs(int n, int i) {
	if (i==n)
		printf("%s\n", s.c_str());
	else {
		s[i] = '0';
		dfs(n, i+1);
		s[i] = '1';
		dfs(n, i+1);
	}
}

int main() {
	while (cin >> n) {
		s.assign(n, '0');
		dfs(n, 0);
	}
}