#include <iostream>
using namespace std;
int n, r, g, b, i;
double all, x, y, z;

inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
int main() {
	while (cin >> n) {
		for (n*=n,all=i=0; i<n; i++) {
			in(r), in(g), in(b);
			x = 5149 * r + 3244 * g + 1607 * b;
			y = 2654 * r + 6704 * g +  642 * b;
			z =  248 * r + 1248 * g + 8504 * b;
			printf ("%.4lf %.4lf %.4lf\n", x/10000, y/10000, z/10000);
			all += y/10000;
		}
		printf ("The average of Y is %.4lf\n", all/n);
	}
}