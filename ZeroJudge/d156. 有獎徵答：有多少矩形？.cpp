#include <iostream>
int t, n, x, y, i, j, k, l, ans;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}
int main() {
	for (in(t); t--; ) {
		bool map[101][101]={};
		for (in(n); n--; ) {
			in(x), in(y);
			map[y][x] = true;
		}
		for (ans=j=0; j<100; j++)
			for (i=0; i<100; i++)
				if (map[j][i])
					for (k=i+1; k<101; k++)
						if (map[j][k])
							for (l=j+1; l<101; l++)
								if (map[l][i]&&map[l][k])
									ans++;
		printf("%d\n", ans);
	}
}