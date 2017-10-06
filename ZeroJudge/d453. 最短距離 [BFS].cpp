#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct data {
	int x, y, step;
}now, next;
bool walked[100][100];
int MoveX[4] = {0, 0, -1, 1}, MoveY[4] = {-1, 1, 0, 0}; //上下左右

int main() {
	int N, n, m, StartX, StartY, EndX, EndY, i;
	string map[100];
	cin >> N;
	while (N--) {
		memset(walked, 0, sizeof(walked));		//陣列從頭到尾歸零
		cin >> n >> m >> StartY >> StartX >> EndY >> EndX;
		for (i=0; i<n; i++)
			cin >> map[i];
		StartX--, StartY--, EndX--, EndY--;		//把X,Y都往左上移一(1,1)→(0,0)
		next.x = StartX;
		next.y = StartY;
		next.step = 1;
		queue <data> q;							//專門存放數據用
		q.push(next);							//把起點丟進第一個
		while (!q.empty()) {					//判斷q裡面是不是空空如也
			now = q.front();					//先把q最前面的數據拿出來當成現在的點
			q.pop();							//再把q最前面的數據丟掉
			if (now.x == EndX && now.y == EndY) break;//已經到終點就出去
			for (i=0; i<4; i++) {				//上下左右各跑一次
				next.x = now.x + MoveX[i];
				next.y = now.y + MoveY[i];
				next.step = now.step + 1;
				if (next.x >= m || next.x < 0 || next.y >= n || next.y < 0 || walked[next.x][next.y] || map[next.y][next.x] == '1') continue; //不搜的條件(出界、走過、撞牆)
				q.push(next);					//通過上述關卡而沒問題的next放進q的最後
				walked[next.x][next.y] = true;	//避免走回頭路紀錄走過的地方
			}
		}
		if (now.x == EndX && now.y == EndY)	cout << now.step << endl;//now是因為踩到終點才出來就輸出now的步數(一定最短，因為是最先到終點的)
		else cout << 0 << endl;					//否則輸出0
	}
}