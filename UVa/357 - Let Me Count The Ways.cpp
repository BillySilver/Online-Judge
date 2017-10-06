#include <iostream>
using namespace std;
long long m[30001]={1}, cent[5]={1,5,10,25,50}, i, j, n;
inline void in(long long &d) {
	char q;
	while (!isdigit(q=getchar())) {
		if(q=-1) {d=-1; return;} }
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
int main() {
	for (i=0; i<5; i++)
		for (j=cent[i]; j<=30000; j++)
			m[j] += m[j-cent[i]];
	while (in(n),n>-1)
		printf(n >= 5 ? "There are %lld ways to produce %lld cents change.\n" : "There is only %lld way to produce %lld cents change.\n", m[n], n);
}