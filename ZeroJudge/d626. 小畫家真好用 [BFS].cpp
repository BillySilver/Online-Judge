#include <iostream>
#include <string>
#include <queue>
using namespace std;
int n, i, j, k, dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
string map[100];
struct data {
	int x, y;
	data(int x, int y) : x(j), y(i) {}
} now(0, 0);

int main() {
	while (cin >> n) {
		for (k=0; k<n; k++)
			cin >> map[k];
		cin >> i >> j;
		queue <data> q;
		q.push(data(i, j));
		while (!q.empty()) {
			now = q.front();
			q.pop();
			for (k=0; k<4; k++) {
				i = now.y + dy[k];
				j = now.x + dx[k];
				if (i<0 || j<0 || i>=n || j>=n || map[i][j]=='+') continue;
				map[i][j] = '+';
				q.push(data(j, i));
			}
		}
		for (k=0; k<n; k++)
			cout << map[k] << endl;
	}
}