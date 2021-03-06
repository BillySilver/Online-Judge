#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
inline int operate(int x, int y, char oper) {
	if (oper=='+') return x+y;
	if (oper=='-') return x-y;
	if (oper=='*') return x*y;
	if (oper=='/') return x/y;
	return x%y;
}

inline bool in(int d = 0, int f = 0) {
	char q;
	while (!isdigit(q=getchar()))
		if (q=='+'||q=='-'||q=='*'||q=='/'||q=='%') {
			f = v.back(), v.pop_back();
			d = v.back(), v.pop_back();
			v.push_back(operate(d, f, q));
		}
		else if (q==10||q==-1)
			return false;
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
	v.push_back(d);
	return true;
}

int main() {
	while (in()) {
		while(in());
		printf("%d\n", v.back());
		v.clear();
	}
}