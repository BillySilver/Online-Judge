#include <iostream>
int n, i, j, b, xy[100][2], odd[2];
bool map[100][100], corrupt;

inline void in(int &d) {
	char q;
	while (q=getchar(), q>57||q<48)
		if (q==-1) break;
	for (d=0; q>=48&&q<=57; q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (in(n), n) {
		for (j=0; j<n; j++)
			for (xy[j][0]=xy[j][1]=i=0; i<n; map[j][i++] = b&1 ? true : false)
				while(b=getchar(), b>49||b<48);
		for (j=0; j<n; j++)
			for (i=0; i<n; i++)
				xy[i][0] += map[j][i], xy[j][1] += map[j][i];
		for (corrupt=odd[0]=odd[1]=i=0; !corrupt&&i<n; i++) {
			for (j=0; j<2; j++) {
				if (xy[i][j]%2) {
					if (odd[j]) {
						corrupt = true;
						break;
					}
					odd[j] = i+1;
				}
			}
		}
		if (corrupt) puts("Corrupt");
		else if (odd[0]&&odd[1]) printf("Change bit (%d,%d)\n", odd[1], odd[0]);
		else puts("OK");
	}
}