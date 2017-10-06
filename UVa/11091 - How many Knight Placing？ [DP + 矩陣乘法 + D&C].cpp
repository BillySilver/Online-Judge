#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#define MOD 10007
using namespace std;
int s[15][6] = {0,0,0,0,1,1}, p[69][2], now[32];
struct Matrix {
	int Sq[69][69];
	inline friend Matrix operator* (Matrix a, Matrix b) {
		int m_i, m_j, m_k;
		Matrix m;
		for (m_i=0; m_i<69; m_i++)
			for (m_j=0; m_j<69; m_j++)
				for (m.Sq[m_i][m_j]=m_k=0; m_k<69; m_k++)
					(m.Sq[m_i][m_j] += a.Sq[m_i][m_k] * b.Sq[m_k][m_j]) %= MOD;
		return m;
	}
} A, ans;

bool check(int x, int y);
bool check2(int x, int y);

int main() {
	int i, j, k, c, n, e;
	for (i=1; i<15; i++) {
		for (j=0; j<6; j++)
			s[i][j] = s[i-1][j];
		next_permutation(s[i], s[i]+6);
	}
	for (k=i=0; i<15; i++)
		for (j=0; j<15; j++)
			if (check(i, j))
				p[k][0] = i, p[k][1] = j, k++;
	for (i=0; i<69; i++) {                //推到最下面是第 i 種雙層
		for (j=0; j<69; j++) {            //查找 i 能推到第 j 種的所有可能
			if (p[j][1] != p[i][0]) continue;
			if (check2(p[j][0], p[i][1]))
				A.Sq[i][j] = 1;
		}
	}
	for (scanf("%d",&c); c--; ) {
		scanf("%d", &n);
		if (n>2) {
			n-=2;
			ans = A;
			for (e=0; n>1; n/=2)
				now[++e] = n;
			for (; e; e--) {
				ans = ans * ans;
				if (now[e]&1)
					ans = ans * A;
			}
			for (k=i=0; i<69; i++)
				for (j=0; j<69; j++)
					k += ans.Sq[i][j];
			printf("%d\n", k%MOD);
		}
		else if (n==2) puts("69");
		else puts("15");
	}
}

bool check(int x, int y) {
	for (int fi=0; fi<6; fi++) {
		if (!s[x][fi]) continue;
		if (fi-2>=0 && s[y][fi-2])
			return false;
		if (fi+2<6 && s[y][fi+2])
			return false;
	}
	return true;
}

bool check2(int x, int y) {
	for (int fi=0; fi<6; fi++) {
		if (!s[x][fi]) continue;
		if (fi-1>=0 && s[y][fi-1])
			return false;
		if (fi+1<6 && s[y][fi+1])
			return false;
	}
	return true;
}