#include <iostream>
int a[27][27][27][27][27], i, j, k, l, m, now;
char q[10];

int main () {
	for (i=0; i<27; i++) {
		for (j=i?i+1:0; j<27; j++) {
			for (k=j?j+1:0; k<27; k++) {
				for (l=k?k+1:0; l<27; l++) {
					for (m=l+1; m<27; m++) {
						a[i][j][k][l][m] = ++now;
					}
				}
			}
		}
	}
	while (q[4]=getchar(), q[4]!=-1) {
		q[4] -= 96;
		for (i=5; q[i]=getchar(),q[i]!=10; i++)
			q[i] -= 96;
		printf("%d\n", a[q[--i-4]][q[i-3]][q[i-2]][q[i-1]][q[i]]);
	}
}