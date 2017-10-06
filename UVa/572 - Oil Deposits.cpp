#include <iostream>
#include <queue>
using namespace std;
int n, m, i, j, dx[8]={0,0,1,-1,1,1,-1,-1}, dy[8]={1,-1,0,0,1,-1,1,-1}, d, deposit;
bool map[100][100];
char g;
struct oil {
	int x, y;
} now, next;

int main() {
	while (cin >> n >> m, n) {
		for (i=0; i<n; i++)
			for (j=0; j<m; map[i][j++]=(g=='@') ? true : false)
				cin >> g;
		for (deposit=i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				if (!map[i][j]) continue;
				map[i][j] = false;
				deposit++;
				now.x = j, now.y = i;
				queue <oil> q;
				for (q.push(now); !q.empty(); ) {
					now = q.front(), q.pop();
					for (d=0; d<8; d++) {
						next.x = now.x + dx[d];
						next.y = now.y + dy[d];
						if (next.x<0||next.y<0||next.x>=m||next.y>=n||!map[next.y][next.x]) continue;
						map[next.y][next.x] = false;
						q.push(next);
					}
				}
			}
		}
		printf("%d\n", deposit);
	}
}