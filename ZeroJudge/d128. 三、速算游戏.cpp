#include <iostream>
int a, b, c, mx;
inline int max(int x, int y) {
	return x > y ? x : y;
}
inline int sa(int x, int y) {
	return max(x+y, x*y);
}

inline int sb(int x, int y, int z) {
	return max( max(x+y+z, x*y*z) , max(x*y+z, x+y*z) );
}

int main() {
	while (~scanf("%d%d%d",&a,&b,&c)) {
		mx = sa(a,b*10+c);
		mx = max(mx, sa(a*10+b,c));
		mx = max(mx, sb(a,b,c));
		printf("%d\n", mx);
	}
}