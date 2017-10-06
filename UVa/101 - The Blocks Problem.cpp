#include <iostream>
#include <string>
using namespace std;
int n, Block[25][25], a, b, i, j, No;
struct location{
	int x, h;
}l[25];
string act1, act2;

int main() {
	while (cin >> n) {
		for (i=0; i<n; i++) {			//積木重設ing
			for (j=0; j<n; j++)
				Block[i][j] = -1;
			Block[i][0] = i;
			l[i].x = i;
			l[i].h = 0;
		}
		while (cin >> act1) {
			if(act1 == "quit") break;
			cin >> a >> act2 >> b;
			if (l[a].x != l[b].x) {
				if (act1 == "move") {
					for (j=n-1; j>l[a].h; j--)							//從a所在地的積木堆往下找積木(不動到a)
						if (Block[l[a].x][j] >= 0) {
							l[No].x = Block[No][0] = No = Block[l[a].x][j];//將a上面的積木丟回原位並改變位置
							l[No].h = 0;
							Block[l[a].x][j] = -1;						//將原積木放置處歸負
						}
				}
				if (act2 == "onto") {
					for (j=n-1; j>l[b].h; j--)							//從b所在地的積木堆往下找積木(不動到b)
						if (Block[l[b].x][j] >= 0) {
							l[No].x = Block[No][0] = No = Block[l[b].x][j];//將b上面的積木丟回原位並改變位置
							l[No].h = 0;
							Block[l[b].x][j] = -1;						//將原積木放置處歸負
						}
				}
				for (j=l[b].h+1; j<n; j++) {							//j從b的上面一格開始
					if (Block[l[a].x][l[a].h] < 0) break;				//從a到頂沒積木可移時跳出
					if (Block[l[b].x][j] == -1) {						//如果b所在積木堆上面有位置可以堆積木時
						Block[l[b].x][j] = Block[l[a].x][l[a].h];
						Block[l[a].x][l[a].h++] = -1;					//把移過去的積木歸負並將高度加一
					}
				}
				for (j=1; j<n; j++) {
					if (Block[l[b].x][j] >= 0) {
						l[ Block[l[b].x][j] ].x = l[b].x;	//將b所在積木堆整排的積木位置重設
						l[ Block[l[b].x][j] ].h = j;
					}
					else break;							//b所在積木堆找到沒積木時跳出
				}
			}
		}
		for (i=0; i<n; i++) {
			cout << i << ":";
			for (j=0; j<n; j++) {
				if (Block[i][j] >= 0) cout << " " << Block[i][j];
				else break;
			}
			cout << endl;
		}
	}
}