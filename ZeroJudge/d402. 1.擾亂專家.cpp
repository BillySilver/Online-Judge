#include <iostream>
using namespace std;
int a, b;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	in(a), in(b);
	printf("%d %d %u", a, b, a+b);
}