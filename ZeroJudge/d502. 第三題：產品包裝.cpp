#include <iostream>
using namespace std;
int a, b, c, d, all;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar())) {
		if(q==-1){d=-1;return;}}
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	while(in(a), a>-1) {
		in(b), in(c), in(d);
		all = d;		//4*4直接裝箱
		if (a/37 <= c) {
			all += a/37;	//3*3的填補縫隙
			c -= a/37;
			a %= 37;
		}
		else {
			all += c;		//3*3和1*1填滿裝箱
			a -= c*37;		//剩下一大堆1*1
			c = 0;
		}
		all += b/8;		//2*2八個直接裝箱
		b %= 8;
		if (b > 0) {
			a -= 64-8*b;	//2*2的填補縫隙
			a = a > 0 ? a : 0;
			all++;			//2*2剩下以及一些1*1裝箱
		}
		if (c > 0)			//至今只有兩種情況：a可能有剩c=0 以及 c有剩a不夠填
			all += c;		//剩下的3*3和1*1裝箱
		else 
			all += a/64 + !!(a%64);
		printf("%d\n", all);
	}
}