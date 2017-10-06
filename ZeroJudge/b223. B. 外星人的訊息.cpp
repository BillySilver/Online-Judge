#include <iostream>
#include <string>
using namespace std;
int n, m;
string s, a;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

inline void Sin(string &d) {
	char q;
	while (q=getchar(), q==10||q==32);
	for (d=""; q!=10&&q!=32; q=getchar())
		d += q;
}

int main() {
	Sin(s);
	while (Sin(a), a[1]!='N'){
		if (a[0]=='A')
			if(a[2]=='D')
				Sin(a), s += a;
			else 
				Sin(a), s = a + s;
		else if (a[0]=='S')
			if (a[1]=='U')
				in(n), in(m), s.assign(s, n-1, m-n+1);
			else
				in(n), s.insert(n-1, 1, '_');
		else
			in(n), in(m), s.erase(n-1, m-n+1);
		puts(s.c_str());
	}
}
