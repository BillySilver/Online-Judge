#include <iostream>
using namespace std;
int m[7850]={1}, cent[5]={1,5,10,25,50}, i, j, n;
inline void in(long long &d) {
	char q;
	while (!isdigit(q=getchar()))
		if(q=-1) {d=-1; return;}
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
int main() {
	for (i=0; i<5; i++)
		for (j=cent[i]; j<=7489; j++)
			m[j] += m[j-cent[i]];
	while (in(n),n>-1)
		printf("%d\n", m[n]);
}