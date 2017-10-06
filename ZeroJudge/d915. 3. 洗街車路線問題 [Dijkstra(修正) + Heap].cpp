#include <iostream>
#include <stdio.h>
using namespace std;

struct emt {							//元素型態(可自訂)
	int w, e;
	friend bool compare(emt a, emt b) {	//比較函式(可自訂)
		return a.w < b.w;
	}
	friend void swap(emt &a, emt &b) {	//交換函式
		emt temp = a;
		a = b, b = temp;
	}
};

struct heap {
	short length;						//heap 的目前大小
	emt node[5001];						//heap 大小(可自訂)
	void push(emt p) {					//元素放入 heap
		short l = ++this->length;
		emt *nd = this->node;
		nd[l] = p;
		while (l-1 && compare(nd[l], nd[l/2])) {
			swap(nd[l], nd[l/2]);
			l /= 2;
		}
	}
	emt root() {						//heap 的極值
		return this->node[1];
	}
	void pop() {						//將 heap 的極值丟棄，並調整 heap
		short &l = this->length;
		emt *nd = this->node;
		nd[1] = nd[l];
		l--;
		short pa=1, sn=2;
		while (sn <= l && (compare(nd[sn], nd[pa]) || compare(nd[sn+1], nd[pa]))) {
			if (compare(nd[sn], nd[sn+1])) {
				swap(nd[pa], nd[sn]);
				sn = (pa=sn) << 1;
			}
			else {
				swap(nd[pa], nd[sn+1]);
				sn = (pa=sn+1) << 1;
			}
		}
	}
	emt take() {						//取走 heap 的極值
		emt temp = root();
		pop();
		return temp;
	}
};

int map[1501][1501], side[1501], odd[15], ol[15][15], n, m, on;	//map為邊權 side記錄點上邊 odd記錄奇點座標 ol為各奇點間最短路徑 on為奇點數
bool ov[15];			//ov記錄已配對奇點(奇點配對用)

int dijkstra(int s, int e) {
	int i, j;
	bool visited[1501] = {};	//為了優化，若某點已經被拜訪過，表示之後的路徑都不會再更短(大於等於)，於是不再Branch
	emt now, next;
	heap h;
	now.e = s;
	now.w = 0;
	h.push(now);
	while (1) {
		now = h.take();
		visited[now.e] = true;					//新增條件：透過Heap抵達的點肯定是已透過最短路徑才抵達，因此記錄下來，未來不再拜訪
		if (now.e == e) return now.w;			//如果目前heap裡權重最小的路徑最終是通往終點 演算法結束
		for (j=1; j<=n; j++) {					//尋找"取出的路徑終點"能走的路
			if (!visited[j] && map[now.e][j]) {	//*與原先版本不同，這裡排除已經拜訪過的點，因為這種演算法不會再讓距離有機會Relaxing
				next.e = j;
				next.w = now.w + map[now.e][j];
				h.push(next);
			}
		}
	}
}


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
	for (i=1; i<=on; i++)						//運用 Dijkstra's algorithm 尋找奇點間最短距離
		for (j=i+1; j<=on; j++)
			ol[i][j] = ol[j][i] = dijkstra(odd[i], odd[j]);
	if (on)										//如果有奇點存在 尋找各種匹配最小值
		for (exl=1<<30,i=2; i<=on; i++)
			exl = min(exl, oddmatch(1, i, on-2));
	else exl = 0;
	printf("%d\n", exl+sum);
}