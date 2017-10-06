#include <iostream>
int m, n, w, h, i, j, k ,l, t, f;
char p[10][40][40], pic[40][40];

int main() {
	scanf("%d%d%d%d", &m, &n, &w, &h),getchar();
	for (i=0; i<m; i++)
		for (j=0; j<h; j++)
			gets(p[i][j]);
	for (l=0; l<n; l++) {
		for (j=0; j<h; j++)
			gets(pic[j]);
		for (i=0; i<m; i++) {
			for (t=f=j=0; j<h; j++) {
				for (k=0; k<w; k++) {
					if (p[i][j][k]=='-') continue;
					p[i][j][k] == pic[j][k] ? t++ : f++;
				}
			}
			if (t >= f*4) {
				puts("Y");
				break;
			}
		}
		if (i == m) puts("N");
	}
}