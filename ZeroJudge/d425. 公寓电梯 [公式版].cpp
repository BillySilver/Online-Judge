#include <iostream>
using namespace std;
long long k, i;
inline void in(long long &d) {
	char q;
	while (!isdigit(q=getchar()))
		if(q==-1) break;
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (in(k), k) {
		if (k%3==1) printf("%d ", k-(k-1)/3);
		printf("%d\n", k-(k-2)/3);
	}
}

/*用暴力解推出的規律
1  1 2
2  2
3  3
4  3 4
5  4
6  5
7  5 6
8  6
9  7
10 7 8
11 8
12 9
13 9 10
*/