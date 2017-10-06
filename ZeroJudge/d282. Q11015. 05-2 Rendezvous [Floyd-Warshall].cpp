#include <iostream>
#include <string>
using namespace std;

int main() {
	int map[23][23], n, m, i, j, k, a, b, tc, mtc, min_i, counter=0;
	string name[23];
	while (cin >> n >> m, n+m){
		for (i=1; i<=n; i++) {	
			for (j=1; j<=n; j++)
				map[i][j] = 1000000000;		//讓map[1][1]到map[n][n]預設為極大值
			map[i][i] = 0;					//到自家的距離歸零
		}
		for (i=1; i<=n; i++)
			cin >> name[i];					//依序輸入至名稱列表(name)內
		for (i=1; i<=m; i++) {
			cin >> a >> b >> k;				//輸入第a位與第b位以及家的距離(k)
			map[a][b] = map[b][a] = k;		//雙向距離設定
		}
		for (k=1; k<=n; k++)				//三層迴圈抄捷徑(若走他路較快則距離設為最短的那個)
			for (i=1; i<=n; i++)
				for (j=1; j<=n; j++)
					map[i][j] = min (map[i][j], map[i][k] + map[k][j]);
		mtc = 1000000000;					//最小總花費時間(mtc)預設為極大值
		for (i=1; i<=n; i++) {
			tc = 0;							//總花費時間(tc)歸零
			for (j=1; j<=n; j++)
				tc += map[i][j];			//到第i家的j個人所需總花費時間
			if (tc < mtc) {
				min_i = i;
				mtc = tc;
			}
		}
		cout << "Case #" << ++counter << " : " << name[min_i] << endl;
	}
}