#include <iostream>
using namespace std;
long long m[50001]={1}, cent[10]={1,5,10,20,50,100,200,500,1000,2000}, i, j, n, s;
inline void in() {
	n = 0;
	long long e;
	char q;
replus:
	while (!isdigit(q=getchar()))
		if (q==10) break;
	for (e=0; isdigit(q); q=getchar())
		(e*=10) += q^48;
	n += e;
	if (q!=10)
		goto replus;
}

int main() {
	for (i=0; i<10; i++)
		for (j=cent[i]; j<=50000; j++)
			m[j] += m[j-cent[i]];
	while (in(), n)
		printf("%lld\n", m[n]-1);
}