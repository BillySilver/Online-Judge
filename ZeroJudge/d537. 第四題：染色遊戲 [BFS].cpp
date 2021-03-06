#include <iostream>
#include <queue>
using namespace std;
int n, ar[8], i, t, mx, x[5], y[5];
char q, c, as[90], map[100][100], dx[8]={0, 1, 1, 1, 0, -1, -1, -1}, dy[8]={1, 1, 0, -1, -1, -1, 0, 1};
struct location {
	int x, y, clr, t;
} now, next;
queue <location> qu;
inline void in(int &d) {
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); (d*=10)+=q^48, q=getchar());
}
int main () {
	as['R'] = 1, as['Y'] = 2, as['B'] = 4, as['O'] = 3, as['P'] = 5, as['G'] = 6, as['D'] = 7;
	in(n), ar[0] = n*n;
	for (i=0; i<3; i++)
		in(x[as[c=getchar()]]), in(y[as[c]]);
	while(!isalpha(c = getchar()));
	for (i=1; i<5; i*=2)
		ar[ map[ now.y=y[i] ][ now.x=x[i] ] = now.clr = i ] = 1, qu.push(now);
	while (!qu.empty()) {
		now = qu.front(), qu.pop();
		/*if (now.t == 1) //查看第t秒顏色用
			system("pause");*/
		if (now.t == t && t++)
			mx = ar[as[c]]>mx ? ar[as[c]] : mx;
		for (i=0; i<8; i++) {
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			if (next.x<0 || next.y<0 || next.x>=n || next.y>=n || map[next.y][next.x]==now.clr) continue;
			next.t = now.t + 1;
			ar[map[next.y][next.x]]--;
			ar[ next.clr = map[next.y][next.x] |= now.clr ]++;
			qu.push(next);
		}
	}
	printf("%d\n", mx);
}

/*
001 1 紅 R
010 2 黃 Y
100 4 藍 B

011 3 橘 O (紅+黃)
101 5 紫 P (紅+藍)
110 6 綠 G (黃+藍)

000 0 白
111 7 黑 D
*/