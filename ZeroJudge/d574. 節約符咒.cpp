#include <iostream>
#include <string>
using namespace std;
int n, i, c, t;
string s, a, num;

int main() {
	cin >> n >> s;	
	for (t=s[0],c=1,i=1; i<n; i++) {
		if (t!=s[i]) {
			num = "";
			while (c) {
				num.insert(0, 1, c%10+48);
				c/=10;
			}
			a.append(num);
			a.append(1, t);
			t = s[i];
			c = 1;
		}
		else c++;
	}
	num = "";
	while (c) {
		num.insert(0, 1, c%10+48);
		c/=10;
	}
	a.append(num);
	a.append(1, t);
	printf("%s", a.size()<n ? a.c_str() : s.c_str());
}