#include <iostream>
int a[27][27][27][27][27], i, j, k, l, m, now;
char q[10];

int main () {
	for (i=0; i<23; i++)
		for (j=i+(i>0); j<27; j++)
			for (k=j+(j>0); k<27; k++)
				for (l=k+(k>0); l<27; l++)
					for (m=l+1; m<27; m++)
						a[i][j][k][l][m] = ++now;
	for (; q[4]=getchar(),(q[4]-=96)!=-97; printf("%d\n", a[q[--i-4]][q[i-3]][q[i-2]][q[i-1]][q[i]]))
		for (i=5; q[i]=getchar(),q[i]!=10; q[i++]-=96);
}