#include <iostream>
#include <cmath>
using namespace std;
int n, m, t, half, ac, ad, bc, bd;

int max(int a, int b) {
	return (a>b) ? a : b;
}

int main () {
	while (cin >> n >> m >> t) {
		for (half=max(n+m,t+m); half<n+m+t; half++) {
			ac = half-m-t;
			ad = n-ac;
			//bc = m;
			bd = t-ad;
			if (ac<1||ad<1||bd<1) continue;
			if (ac*bd==ad*m)
				break;
		}
		printf("%d\n", half-ad);
	}
}