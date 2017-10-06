#include <iostream>
#include <stdio.h>
#include <string.h>								// for memset
#include <map>
#include <string>
#define MaxN 100
#define MaxM 100
#define MaxK 100
#define MaxAdter MaxN+MaxM+2*MaxK				// 轉接器最大可能的插座種類數
using namespace std;

bool adapter[MaxAdter][MaxAdter], adj[MaxN][MaxAdter];
int match[MaxM];								// 插座插了那些裝置
bool chk[MaxM];									// 插座在dfs中訪問過與否
map<string, int> s_num;							// 插座與其編號之mapping
int s_cnt;										// 目前在map s_num裡面有多少映射關係。也就是有多少種插座

bool dfs(int i, int n, int m) {
	for (int j=0; j<m; j++) {
		if (adj[i][j] && !chk[j]) {				// 找到未嘗試過的插座j，且裝置i可以插在該插座。
			chk[j] = true;
			// 兩種匹配增加一的情況: 1.該插座本來就沒有插任何裝置。 2.這樣的組合在未來還能讓其他「未使用的裝置」插入。
			if (match[j]==-1 || dfs(match[j], n, m)) {
				match[j] = i;					// 插座j換插裝置i
				return true;
			}
		}
	}
	return false;								// 裝置i永遠無法插入任何插座，唉
}

int bipartite(int n, int m) {
	memset(match, -1, sizeof(match));			// 一開始裝置沒有插進任何插座
	int res = 0;
	for (int i=0; i<n; i++) {					// 探索各個裝置，能不能搶走某(未/已使用)插座，而不減少已插的裝置量。
		memset(chk, false, sizeof(chk));
		if (dfs(i, n, m))
			res++;
	}
	return res;
}

// 裝置名稱可能從未出現，在取其值之前先做檢查
int getS_num(string const &key) {
	if ( s_num.end() == s_num.find(key) )		// 找不到
		s_num[key] = s_cnt++;
	return s_num[key];
}

int main() {
	int cases;
	int n, m, k;
	string gar, gar2;
	// FILE* fPtr = fopen("out.txt", "w");
	for (cin >> cases; cases--; ) {
		cin >> n;
		memset(adj, false, sizeof(adj));
		memset(adapter, false, sizeof(adapter));
		s_num.clear();
		// 輸入既有Socket。建立Socket名字與編號的map
		for (int j = 0; j < n; ++j) {
			cin >> gar;
			s_num[gar] = j;
		}
		s_cnt = n;
		// 輸入Device與Socket之對應關係。Device名稱不重要
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> gar >> gar2;
			adj[i][ getS_num(gar2) ] = true;
		}
		// 輸入Adapter。可能會出現新種Socket
		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> gar >> gar2;
			adapter[ getS_num(gar) ][ getS_num(gar2) ] = true;
		}
		// 建立Adapter間的「遞移閉包」
		for (int i = 0; i < s_cnt; ++i)
			adapter[i][i] = true;
		for (int k = 0; k < s_cnt; ++k)
			for (int i = 0; i < s_cnt; ++i)
				for (int j = 0; j < s_cnt; ++j)
					if (adapter[i][k] && adapter[k][j])
						adapter[i][j] = true;
		// 建立裝置和所有插座的對應邊，忽略Adapter
		for (int k = 0; k < s_cnt; ++k)
			for (int i = 0; i < m; ++i)
				for (int j = 0; j < n; ++j)
					if (adj[i][k] && adapter[k][j])
						adj[i][j] = true;
		// (插座, 裝置) 順序改成 (裝置, 插座)送進 bipartite
		/*
		fprintf(fPtr, "%d\n", m-bipartite(m, n));
		if (cases) fprintf(fPtr, "\n");
		//*/
		//*
		printf("%d\n", m-bipartite(m, n));
		if (cases) printf("\n");
		//*/
	}
}