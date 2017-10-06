#include <iostream>
#include <stdio.h>
#define INFINITY 1<<30
using namespace std;

int map[1501][1501], side[1501], odd[15], ol[15][15], n, m, on;	//map為邊權 side記錄點上邊 odd記錄奇點座標 ol為各奇點間最短路徑 on為奇點數
bool ov[15];			//ov記錄已配對奇點(奇點配對用)

int oddmatch(int s, int e, int oddr) {			//奇點配對 oddr為奇點剩餘個數
	if (!oddr) return ol[s][e];					//已無奇點直接回傳 (s, e) 最短路徑當匹配
	int exl = 1<<30, i, j;
	ov[s] = ov[e] = true;
	for (i=2; ov[i]&&i<=on; i++);				//尋找未配對最小奇點
	for (j=i+1; j<=on; j++) {					//並從下一編號開始嘗試與所有未匹配奇點配對
		if (ov[j]) continue;
		exl = min(exl, oddmatch(i, j, oddr-2));	//記錄各種匹配最小值
	}
	ov[s] = ov[e] = false;
	return ol[s][e] + exl;						//(s, e)最短路徑為一匹配 回傳其與各種匹配最小值的和
}
int main() {
	int i, j, x, y, w, exl, sum;
	scanf("%d%d%d", &n, &m, &i);
	for (sum=i=0; i<m; i++) {
		scanf("%d%d%d", &x, &y, &w);
		sum += (map[x][y] = map[y][x] = w);		//輸入邊時直接記錄總和 因至少每邊都會走一次 走兩次以上是為了讓奇點通往奇點(稍後奇點配對處理)
		side[x]++; side[y]++;					//記錄點上邊
	}
	for (on=i=0; i<=n; i++)
		if (side[i]&1) odd[++on] = i;			//找奇點順便記奇點個數
	for (i=1; i<=on; i++)
		for (j=i; j<=on; j++)
			ol[i][j] = INFINITY;
	for (int k=1; k<=n; k++)					//運用 Floyd-Warshall Algorithm 尋找奇點間最短距離
		for (i=1; i<=on; i++)
			for (j=1; j<=on; j++)
				if (map[k][ odd[j] ] && ol[i][j] > ol[i][k]+map[k][ odd[j] ])
				ol[i][j] = ol[i][k]+map[k][ odd[j] ];
	if (on)										//如果有奇點存在 尋找各種匹配最小值
		for (exl=1<<30,i=2; i<=on; i++)
			exl = min(exl, oddmatch(1, i, on-2));
	else exl = 0;
	printf("%d\n", exl+sum);
}