#include <iostream>
using namespace std;
int i, x, y, line, sco, s[3][3]={{8,5,8},{5,2,5},{8,5,8}};
bool sq[3][3];

int main() {
	for (line=sco=i=0; i<9; i++) {
		scanf("%d%d",&x,&y);
		if (x>=30||y>=30||x<=0||y<=0||x==10||x==20||y==10||y==20||sq[x/10][y/10]) continue;
		sco += s[x/10][y/10];
		sq[x/10][y/10] = true;
	}
	for (i=0; i<3; i++) {
		if (sq[i][0]&&sq[i][1]&&sq[i][2]) line++;
		if (sq[0][i]&&sq[1][i]&&sq[2][i]) line++;
	}
	printf("%d %d\n", line, sco);
}