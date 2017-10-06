#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int n, i, j, k, c, x[201], y[201];
double fd[201][201];

int main() {
	while (cin >> n, n) {
		for(i=1; i<=n; i++) {
			scanf("%d%d", &x[i] ,&y[i]);	//輸入石頭1~n
			for (j=i-1; j>=0; j--)			//每輸入一次，就紀錄和之前的每顆石頭的直線距離
				fd[i][j] = fd[j][i] = sqrt(double(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
		}
		for (k=1; k<=n; k++)
			for (j=1; j<=n; j++)
				for (i=1; i<=n; i++)
					fd[i][j] = min( max(fd[i][k], fd[k][j]), fd[i][j] );//三角形ikj找除了斜邊外最長的邊
		cout << "Scenario #" << ++c << "\nFrog Distance = " << fixed << setprecision(3) << fd[1][2] << endl;
	}
}