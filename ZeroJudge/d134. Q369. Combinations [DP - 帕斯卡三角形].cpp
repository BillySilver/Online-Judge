#include <iostream>
using namespace std;
int i, j, n, m;
unsigned long long c[101][101]={1};
inline void in(int &d) {
	char q;
	while ((q=getchar())==10);
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}

int main() {
	for (i=1; i<101; c[i++][0]=c[i][j]=1)
		for (j=1; j<i; j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	while (in(n), in(m), n) 
		printf("%d things taken %d at a time is %llu exactly.\n", n, m, c[n][m]);
}