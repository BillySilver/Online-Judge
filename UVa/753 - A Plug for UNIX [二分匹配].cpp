#include <iostream>
#include <stdio.h>
#include <string.h>								// for memset
#include <map>
#include <string>
#define MaxN 100
#define MaxM 100
#define MaxK 100
#define MaxAdter MaxN+MaxM+2*MaxK				// �౵���̤j�i�઺���y������
using namespace std;

bool adapter[MaxAdter][MaxAdter], adj[MaxN][MaxAdter];
int match[MaxM];								// ���y���F���Ǹ˸m
bool chk[MaxM];									// ���y�bdfs���X�ݹL�P�_
map<string, int> s_num;							// ���y�P��s����mapping
int s_cnt;										// �ثe�bmap s_num�̭����h�֬M�g���Y�C�]�N�O���h�ֺش��y

bool dfs(int i, int n, int m) {
	for (int j=0; j<m; j++) {
		if (adj[i][j] && !chk[j]) {				// ��쥼���չL�����yj�A�B�˸mi�i�H���b�Ӵ��y�C
			chk[j] = true;
			// ��ؤǰt�W�[�@�����p: 1.�Ӵ��y���ӴN�S��������˸m�C 2.�o�˪��զX�b�����ٯ�����L�u���ϥΪ��˸m�v���J�C
			if (match[j]==-1 || dfs(match[j], n, m)) {
				match[j] = i;					// ���yj�����˸mi
				return true;
			}
		}
	}
	return false;								// �˸mi�û��L�k���J���󴡮y�A��
}

int bipartite(int n, int m) {
	memset(match, -1, sizeof(match));			// �@�}�l�˸m�S�����i���󴡮y
	int res = 0;
	for (int i=0; i<n; i++) {					// �����U�Ӹ˸m�A�ण��m���Y(��/�w�ϥ�)���y�A�Ӥ���֤w�����˸m�q�C
		memset(chk, false, sizeof(chk));
		if (dfs(i, n, m))
			res++;
	}
	return res;
}

// �˸m�W�٥i��q���X�{�A�b����Ȥ��e�����ˬd
int getS_num(string const &key) {
	if ( s_num.end() == s_num.find(key) )		// �䤣��
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
		// ��J�J��Socket�C�إ�Socket�W�r�P�s����map
		for (int j = 0; j < n; ++j) {
			cin >> gar;
			s_num[gar] = j;
		}
		s_cnt = n;
		// ��JDevice�PSocket���������Y�CDevice�W�٤����n
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> gar >> gar2;
			adj[i][ getS_num(gar2) ] = true;
		}
		// ��JAdapter�C�i��|�X�{�s��Socket
		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> gar >> gar2;
			adapter[ getS_num(gar) ][ getS_num(gar2) ] = true;
		}
		// �إ�Adapter�����u�������]�v
		for (int i = 0; i < s_cnt; ++i)
			adapter[i][i] = true;
		for (int k = 0; k < s_cnt; ++k)
			for (int i = 0; i < s_cnt; ++i)
				for (int j = 0; j < s_cnt; ++j)
					if (adapter[i][k] && adapter[k][j])
						adapter[i][j] = true;
		// �إ߸˸m�M�Ҧ����y��������A����Adapter
		for (int k = 0; k < s_cnt; ++k)
			for (int i = 0; i < m; ++i)
				for (int j = 0; j < n; ++j)
					if (adj[i][k] && adapter[k][j])
						adj[i][j] = true;
		// (���y, �˸m) ���ǧ令 (�˸m, ���y)�e�i bipartite
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