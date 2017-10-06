#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int n, i, j, k, c, x[201], y[201];
double fd[201][201];

int main() {
	while (cin >> n, n) {
		for(i=1; i<=n; i++) {
			scanf("%d%d", &x[i] ,&y[i]);	//��J���Y1~n
			for (j=i-1; j>=0; j--)			//�C��J�@���A�N�����M���e���C�����Y�����u�Z��
				fd[i][j] = fd[j][i] = sqrt(double(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
		}
		for (k=1; k<=n; k++)
			for (j=1; j<=n; j++)
				for (i=1; i<=n; i++)
					fd[i][j] = min( max(fd[i][k], fd[k][j]), fd[i][j] );//�T����ikj�䰣�F����~�̪�����
		cout << "Scenario #" << ++c << "\nFrog Distance = " << fixed << setprecision(3) << fd[1][2] << endl;
	}
}