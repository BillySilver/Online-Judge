#include <stdio.h>
int n, c;
char s[31];
bool dp[31][11][1024];	//[0~30][0~10][0~2^10-1] [ヘ玡じ][程Юじ计][程Ю搓Θ计]

int takeb(int st, int num, int f) {
	return (st & (1<<num)-1 << f*num) >> f*num;
}

bool check(int a, int b, int c) {
	return a==b && b==c && c==a;
}

int ans(int f, int st) {
	int i, temp = 0;
	for (i=1; i<=f/3; i++)
			if ( check( takeb(st, i, 2) , takeb(st, i, 1) , takeb(st, i, 0) ) ) return 0;
	if (!s[f+1]) return 1;
	if (s[f+1] != '1') temp += ans(f+1, st*2);
	if (s[f+1] != '0') temp += ans(f+1, st*2+1);
	return temp;
}

int main() {
	int i, j, k;
	while (scanf("%d", &n), n) {
		scanf(" %s", s+1);
		printf("Case %d: %d\n", ++c, ans(0, 0));
	}
}