#include <iostream>
using namespace std;
int a[100001], n, ls, rs, i, l, r, same;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
int main() {
	for (in(n),i=0; i<n; in(a[i++]));
	for (l=0,r=n-1,ls=a[l],rs=a[r]; l!=n-1&&r!=0; ) {
		if (ls==rs) {
			same++;
			ls += a[++l];
			rs += a[--r];
		}
		else if (ls > rs) rs +=a[--r];
		else ls +=a[++l];
	}
	if (!r) {
		for (; l!=n-1; ls += a[++l])
			if (ls==rs) same++;
	}
	else {
		for (; r!=0; rs +=a[--r])
			if (ls==rs) same++;
	}
	printf("%d\n", same+1);
}