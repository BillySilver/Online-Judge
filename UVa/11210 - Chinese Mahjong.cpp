#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;
const char u[4] = "TSW";
int ascii[255], p[29], pn[34], temp[13], cas, ans[34], tail;
const string wind[7] = {"DONG", "NAN", "XI", "BEI", "ZHONG", "FA", "BAI"};
bool use[34], combine[29];

int s_hash(string fs) {
	if (fs[0] <= '9')
		return ascii[fs[1]]*9 + fs[0]-'1';
	for (int i=0; i<7; i++)
		if (fs == wind[i])
			return 27+i;
	return -1;
}

bool setuse(int fs, bool st=true) {
	if (!st)
		return use[fs];
	return use[fs] = true;
}

bool dfs(int i, bool eye) {			//讓第 i 張牌一定要用到
	int j, k;
	for (     ; combine[i] || !~p[i]; i++);
	for (j=i+1; combine[j] || !~p[j]; j++);
	for (k=j+1; combine[k] || !~p[k]; k++);
	if ((!~p[27] && i >= 27) || i >= 28) return true;
	if (!eye && p[i] == p[j]) {
		combine[i] = combine[j] = true;
		if (dfs(k, true))
			return true;
		combine[i] = combine[j] = false;
	}
	if ((!~p[27] && k >= 27) || k >= 28)
		return false;
	if (p[i] == p[j] && p[i] == p[k] && p[k] == p[j]) {
		combine[i] = combine[j] = combine[k] = true;
		if (dfs(k+1, eye))
			return true;
		combine[i] = combine[j] = combine[k] = false;
	}
	if (p[i]/9 < 3) {
		for (j=i+1; p[i]/9==p[j]/9 || !~p[j]; j++)
			if (!combine[j] && p[j]-p[i] == 1) break;
		for (k=j+1; p[i]/9==p[k]/9 || !~p[k]; k++)
			if (!combine[k] && p[k]-p[j] == 1) break;
		if (p[i]/9==p[j]/9 && p[i]/9==p[k]/9 && p[j]-p[i]==1 && p[k]-p[j]==1) {
			combine[i] = combine[j] = combine[k] = true;
			if (dfs(i+1, eye))
				return true;
			combine[i] = combine[j] = combine[k] = false;
		}
	}
	return false;
}

inline void insert(int loc, int fs) {
	if (setuse(fs, 0)) return;
	setuse(fs);
	p[2*loc+1] = fs;
	memset(combine, 0, sizeof(combine));
	if (dfs(0, false))
		ans[tail] = fs, tail++;
	p[2*loc+1] = -1;
}

int main() {
	int i;
	string s;
	ascii['T'] = 0, ascii['S'] = 1, ascii['W'] = 2;
	while (cin >> s, s!="0") {
		memset(pn, 0, sizeof(pn));
		temp[0] = s_hash(s);
		pn[ temp[0] ]++;
		for (i=1; i<13; i++) {
			cin >> s;
			temp[i] = s_hash(s);
			pn[ temp[i] ]++;
		}
		sort(temp, temp+13);
		/*if (cas == 4) {
			for (i=10; i<13; i++)
				printf("%d ", temp[i]);
			puts("");
		}
		*/
		memset(p, -1, sizeof(p));
		for (i=1; i<=13; i++) {
			p[i*2] = temp[i-1];
		}
		p[28] = 100;
		memset(use, 0, sizeof(use));
		tail = 0;
		printf("Case %d:", ++cas);
		for (i=1; i<=13; i++) {
			if (pn[p[i*2]] < 4)
				insert(i, p[i*2]);
			if (p[i*2]/9 < 3 && (p[i*2]+1)%9 && pn[p[i*2]+1] < 4 && p[i*2] < p[i*2+2])
				insert(i, p[i*2]+1);
			if (p[i*2]/9 < 3 && p[i*2]%9 && pn[p[i*2]-1] < 4)
				insert(i-1, p[i*2]-1);
		}
		if (tail) {
			sort(ans, ans+tail);
			for (i=0; i<tail; i++) {
				int fs = ans[i];
				if (fs/9 < 3)
					printf(" %d%c", fs%9+1, u[fs/9]);
				else printf(" %s", wind[fs-27].c_str());
			}
			puts("");
		}
		else puts(" Not ready");
	}
}