#include <iostream>
#include <stdio.h>
int n, i, p;
double x[2][10], y[2][10], a, b;
char q;

int main() {
	for (n=0; q=getchar(), q!='*'; n++) {
		scanf("%lf%lf%lf%lf",&x[0][n],&y[0][n],&x[1][n],&y[1][n]);
		while (q=getchar(), q!=10);
	}
	for (p=1; scanf("%lf%lf",&a,&b), !(a==b&&a==9999.9); p++) {
		for (q=i=0; i<n; i++)
			if (a>x[0][i]&&a<x[1][i]&&b>y[1][i]&&b<y[0][i]&&(q=1))
				printf("Point %d is contained in figure %d\n", p, i+1);
		if (!q) printf("Point %d is not contained in any figure\n", p);
	}
}