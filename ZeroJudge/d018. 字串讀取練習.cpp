#include <iostream>
using namespace std;
double a, b;

inline bool in(void) {
	int now;
	double num;
	char ch;
	while (ch=getchar(), ch==10);
	a = b = now = 0;
	do {
		if (ch == -1)
			return false;
		if (ch == ':') {
			cin >> num;
			(now%2) ? a+=num : b+=num;
			now = 0;
			if((ch=getchar())==10) break;
			continue;
		}
		(now*=10) += ch^48;
	}
	while (ch=getchar(), ch!=10);
	return true;
}

int main() {
	while (in())
		cout << a-b << endl;
}