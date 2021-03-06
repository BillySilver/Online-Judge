#include <iostream>
#include <queue>
using namespace std;
int MoveX[8] = {1,-1,-3,-3,-1,1,3,3}, MoveY[8] = {3,3,1,-1,-3,-3,-1,1}, n, i, x, y, Ex, Ey, ObX[8] = {0,0,-1,-1,0,0,1,1}, ObY[8] = {1,1,0,0,-1,-1,0,0};
bool walked[100][100], map[100][100];
struct data {
	int x, y, step;
}now, next;
queue <data> q;

int main() {
	while (cin >> n) {
		memset(walked, 0, sizeof(walked));
		memset(map, 0, sizeof(map));
		for (i=0; i<n; i++) {
			scanf("%d%d", &x, &y);
			walked[x][y] = map[x][y] = true;
		}
		scanf("%d%d%d%d", &x, &y, &Ex, &Ey);
		now.x = x;
		now.y = y;
		now.step = 0;
		q.push(now);
		while (!q.empty()) {
			now = q.front();
			q.pop();
			if (now.x == Ex && now.y == Ey) break;
			for (i=0; i<8; i++) {
				if (map[now.x+ObX[i]][now.y+ObY[i]]) continue;
				next.x = now.x + MoveX[i];
				next.y = now.y + MoveY[i];
				next.step = now.step + 1;
				if (next.x > 99 || next.x < 0 || next.y > 99 || next.y < 0 || walked[next.x][next.y]) continue;
				q.push(next);
				walked[next.x][next.y] = true;
			}
		}
		if (now.x == Ex && now.y == Ey) printf("%d\n", now.step);
		else printf("impossible\n");
	}
}