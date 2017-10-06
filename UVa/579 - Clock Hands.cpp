#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main()  {
	float h,m,ha,ma,a;
	char g;
	while (cin >> h >> g >> m,h+m) {
		if (h == 12) h = 0;
		ha=(h*30+m/2);
		ma=m*6;
		a = abs(ha-ma);
		if (a > 180) a = 360-a;
		cout << fixed << setprecision(3) << a << endl;
	}
}