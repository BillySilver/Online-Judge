#include <iostream>
using namespace std;
int sum;

inline bool in(int &d) {
	int now;
	char ch;
	while (ch=getchar(), ch==10);
	d = now = 0;
	do {
		if (ch == -1)
			return false;
		if (ch == 32) {
			d += now;
			now = 0;
			continue;
		}
		if (ch<48||ch>57) {
			now = 0;
			while (ch=getchar(), ch!=10&&ch!=32);
			if (ch==10)	break;
			continue;
		}
		(now*=10) += ch^48;
	}
	while (ch=getchar(), ch!=10);
	d += now;
	return true;
}

int main() {
	while (in(sum))
		cout << sum << endl;
}