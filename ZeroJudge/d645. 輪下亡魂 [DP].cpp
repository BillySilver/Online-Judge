#include <iostream>
using namespace std;
int n, c, dp[1001]={1}, v, w, t, mx, i, j, k;

inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar())) {
		if (q!='-') continue;
		d = -1;
		getchar();
		return;
	}
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
inline int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	for (in(n),in(c); n--; ) {
		in(v), in(w), in(t);	//v飽足感 w體積 t種類
		t *= w;
		if (t < 0) t = 1 << 30;
		for (i=c-w; i>=0; i--)
			if (dp[i])
				for (j=w; j<=t && i+j<=c; j+=w)
					mx = max( dp[i+j]=max(dp[i+j], dp[i+j-w]+v), mx);
	}
	printf("%d", mx-1);
}