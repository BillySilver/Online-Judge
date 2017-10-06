#include <iostream>
using namespace std;
double h, u, d, f, loca, day;
bool can;

int main() {
	while (cin >> h >> u >> d >> f, h) {
		f = u*f/100;
		for (loca=day=0; ; day++) {
			loca += u>f*day ? u-f*day : 0;
			if (loca > h) {
				can = true;
				break;
			}
			loca -= d;
			if (loca < 0) {
				can = false;
				break;
			}
		}
		printf("%s on day %d\n", can ? "success" : "failure", (int)day+1);
	}
}