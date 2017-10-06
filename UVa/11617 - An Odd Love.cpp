#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int t, w, h, dp[2][2], dt; //[左右][編號與步數]
string s;

inline int abs(int x) {
	return x>0 ? x : -x;
}
inline int find(int d) {
	int i;
	if (!d) {
		for (i=0; i<w; i++)
			if (!(s[i]&1)) return i;
		return w;
	}
	for (i=w-1; ~i; i--)
		if (!(s[i]&1)) return i;
	return w;
}

inline int path(int d, int beg, int end) {
	return dp[d][1] + dt + abs(dp[d][0] - beg) + abs(beg - end);
}

int main() {
	int i, l, r, lt, rt;
	for (scanf("%d",&t); t--; printf("%d\n", min(dp[0][1], dp[1][1]))) {
		scanf("%d%d", &w, &h);
		memset(dp, 0, sizeof(dp));
		for (dt=i=0; i<h; i++) {
			cin >> s;
			if ((l=find(0))-w) {
				r = find(1);
				lt = min(path(0, r, l), path(1, r, l));
				rt = min(path(0, l, r), path(1, l, r));
				dp[0][0] = l;
				dp[1][0] = r;
				dp[0][1] = lt;
				dp[1][1] = rt;
				dt = 1;
			}
			else {
				dt++;
				continue;
			}
		}
	}
}