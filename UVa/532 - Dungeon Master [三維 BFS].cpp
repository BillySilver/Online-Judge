#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
int l, r, c, i, j, k, ex, ey, ef, mx[6] = {0,0,-1,1,0,0}, my[6] = {1,-1,0,0,0,0}, mf[6] = {0,0,0,0,1,-1}; //前後左右上下
bool map[31][31][31], walked[31][31][31];
char p;
struct record{
	int x, y, f, m;
}now, next;
int main() {
	while (cin >> l >> r >> c, l+r+c) {
		memset(walked, 0, sizeof(walked));
		memset(map, 0, sizeof(map));
		for (k=0; k<l; k++) {
			for (j=0; j<r; j++) {
				for (i=0; i<c; i++) {
					cin >> p;
					if (p == '#') map[k][j][i] = 1;
					else {
						map[k][j][i] = 0;
						if (p == 'S') {
							next.x = i;
							next.y = j;
							next.f = k;
						}
						else if (p == 'E'){
							ex = i;
							ey = j;
							ef = k;
						}
					}
				}
			}
		}
		next.m = 0;
		walked[next.f][next.y][next.x] = true;
		queue <record> q;
		q.push(next);
		while (!q.empty()) {
			now = q.front();
			q.pop();
			if (now.x == ex && now.y == ey && now.f == ef) break;
			for (i=0; i<6; i++) {
				next.x = now.x + mx[i];
				next.y = now.y + my[i];
				next.f = now.f + mf[i];
				next.m = now.m + 1;
				if (next.x < 0 || next.y < 0 || next.x >= c || next.y >= r || next.f < 0 || next.f >= l || walked[next.f][next.y][next.x] || map[next.f][next.y][next.x]) continue;
				q.push(next);
				walked[next.f][next.y][next.x] = true;
			}
		}
		if (now.x == ex && now.y == ey && now.f == ef)
			cout << "Escaped in " << now.m << " minute(s).\n";
		else printf("Trapped!\n");
	}
}