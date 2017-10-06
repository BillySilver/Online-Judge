#include <iostream>
using namespace std;
long long n, t, m;
struct Matrix_2x2 {
	long long x1, x2,
			  y1, y2;
	inline friend Matrix_2x2 operator*(Matrix_2x2 m1, Matrix_2x2 m2) {
		Matrix_2x2 M;
		M.x1 = (m1.x1 * m2.x1 + m1.x2 * m2.y1) % m;
		M.x2 = (m1.x1 * m2.x2 + m1.x2 * m2.y2) % m;
		M.y1 = (m1.y1 * m2.x1 + m1.y2 * m2.y1) % m;
		M.y2 = (m1.y1 * m2.x2 + m1.y2 * m2.y2) % m;
		return M;
	}
} Matrix, org;

inline Matrix_2x2 exp(long long e) {
	if (e==1) return org;
	Matrix_2x2 MT = exp(e>>1);
	MT = MT * MT;
	if (e&1) MT = MT * org;
	return MT;
}

int main() {
	for (scanf("%d",&n); n--; ) {
		scanf("%lld%lld%lld%lld%lld%lld", &org.x1, &org.x2, &org.y1, &org.y2, &t, &m);
		if (!t)
			puts("Normal");
		else {
			org.x1 = (org.x1%m + m)%m, org.x2 = (org.x2%m + m)%m, org.y1 = (org.y1%m + m)%m, org.y2 = (org.y2%m + m)%m;
			Matrix = exp(t);
			if ( (Matrix.x1=(Matrix.x1+Matrix.x2)%m) > (Matrix.y1=(Matrix.y1+Matrix.y2)%m) )
				puts("Tsundere");
			else if (Matrix.x1 < Matrix.y1)
				puts("Haraguroi");
			else puts("Normal");
		}
	}
}