#include <iostream>
#include <queue>
using namespace std;
int n, i, j, dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
char map[100][100], c;
struct data{
	int x, y, step;
}now, next;

inline void in(int &d) {
	while (!isdigit(c=getchar()));
	for (d=0; isdigit(c); c=getchar())
		(d*=10) += c^48;
}

int main() {
	while (in(n), n) {
		for (i=0; i<n; i++)
			for (j=0; c=getchar(),c!=10; map[i][j++]=c)
				if (c=='K') now.x = j, now.y = i;
		map[now.y][now.x] = '#';
		now.step = 0;
		queue <data> q;
		q.push(now);
		while (!q.empty()) {
			now = q.front();
			if (map[now.y][now.x]=='@') break;
			q.pop();			
			for (i=0; i<4; i++) {
				next.x = now.x + dx[i];
				next.y = now.y + dy[i];
				if (map[next.y][next.x]=='#') continue;
				if (map[next.y][next.x]!='@') map[next.y][next.x] = '#';
				next.step = now.step + 1;
				q.push(next);
			}
		}
		printf(q.empty() ? "= =\"\n" : "%d\n", now.step);
	}
}