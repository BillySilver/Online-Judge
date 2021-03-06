#include <iostream>
using namespace std;
int y, m, d, date[13]={0,31,59,90,120,151,181,212,243,273,304,334,365}, n;
bool BY;

int main () {
	while (cin >> y) {
		scanf("%d%d", &m, &d);
//		if (++n == 23) cout << y << ' ' << m << ' ' << d << endl;
		BY = (!(y%4) && (y%100)) || !(y%400);
		if (date[m]-date[m-1]+(m==2 && d==29 && BY) < d || d<1 || m>12 || m<1 || y<1)	//後面那兩個條件是避免閏年2月29日
			printf("Error\n");
		else {
			d += date[m-1];
			if (BY && m>2)
				d++;
			if (m*d == 1)
				printf("It is 1 day in %d\n", y);
			else
				printf("It is %d days in %d\n", d, y);
		}
	}
}