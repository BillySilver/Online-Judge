#include <iostream>
int now, nw, n, i;
inline void in(int &d, char q=0, bool sign=false) {
	while (!isdigit(q=getchar())) {
		if (q==-1) break;
		if (q=='-') sign = true;
	}
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
	if (sign) d = -d;
}

int main () {
	while (in(n), n) {
		bool ab[3001]={};
		in(now);
		for (i=1; i<n; i++) {
			in(nw);
			ab[(now-=nw) > 0 ? now : -now] = true;
			now = nw;
		}
		for (i=1; ab[i]; i++);
		puts(i==n ? "Jolly" : "Not jolly");
	}
}