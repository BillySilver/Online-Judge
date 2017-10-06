#include <iostream>
using namespace std;
int n, m, a, b, i, j, k;
bool map[200][200], visit[200], color[200], ans;
inline void dfs(int s, int e) {
	if (s==n) return;
	for (; e<n; e++) {
		if (!map[s][e]) continue;
		if (visit[e]) {
			if (color[s]==color[e]) {
				ans = false;
				return;
			}
		}
		else {
			color[e] = !color[s];
			visit[e] = true;
			dfs(e, 1);
		}
	}
}
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (in(n), n) {
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		memset(color, 0, sizeof(color));
		in(m);
		for (i=0; i<m; i++) {
			in(a), in(b);
			map[a][b] = map[b][a] = true;
		}
		ans = true;
		for (i=0; ans&&i<n; i++) {
			visit[i] = true;
			dfs(i, i+1);
		}
		puts(ans ? "BICOLORABLE." : "NOT BICOLORABLE.");
	}
}