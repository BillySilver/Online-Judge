#include <iostream>
using namespace std;
int i, j, a[4][5], asc[255], cd[14];
char c[4][13][2], d;

int main() {
	asc['A']=4, asc['K']=3, asc['Q']=2, asc['J']=1; //點數
	asc['S']=2, asc['H']=3, asc['D']=4, asc['C']=1; //花色
	asc['N']=0, asc['E']=1, asc['S']=2, asc['W']=3; //方位
	for (i=0; i<4; i++)
		for (j=0; j<13; j++)
			scanf("%s",c[i][j]);
	cin >> d;
	for (i=0; i<4; i++)
		for (j=0; j<13; j++)
			a[i][0] += asc[c[i][j][0]], a[i][asc[c[i][j][1]]]++;
	for (i=asc[d]; i<asc[d]+4; i++)
		if (a[i%4][0] >= 12) break;
	if (i==asc[d]+4)
		puts("All Pass");
	else if (a[i%=4][0]>=20) puts("2C");
	else {
		for (j=0; j<4; j++)
			cd[a[i][j]]++;
		if (a[i][0]>=15 && (cd[4]==2&&cd[3]==1 || cd[3]==3))
			puts("1NT");
		else if (a[i][2]>=5) puts("1S");
		else if (a[i][3]>=5) puts("1H");
		else if (a[i][4]>=3) puts("1D");
		else puts("1C");
	}
}