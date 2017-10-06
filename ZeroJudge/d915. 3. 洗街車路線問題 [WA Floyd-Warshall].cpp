#include <iostream>
#include <stdio.h>
#define INFINITY 1<<30
using namespace std;

int map[1501][1501], side[1501], odd[15], ol[15][15], n, m, on;	//map�����v side�O���I�W�� odd�O���_�I�y�� ol���U�_�I���̵u���| on���_�I��
bool ov[15];			//ov�O���w�t��_�I(�_�I�t���)

int oddmatch(int s, int e, int oddr) {			//�_�I�t�� oddr���_�I�Ѿl�Ӽ�
	if (!oddr) return ol[s][e];					//�w�L�_�I�����^�� (s, e) �̵u���|��ǰt
	int exl = 1<<30, i, j;
	ov[s] = ov[e] = true;
	for (i=2; ov[i]&&i<=on; i++);				//�M�䥼�t��̤p�_�I
	for (j=i+1; j<=on; j++) {					//�ñq�U�@�s���}�l���ջP�Ҧ����ǰt�_�I�t��
		if (ov[j]) continue;
		exl = min(exl, oddmatch(i, j, oddr-2));	//�O���U�ؤǰt�̤p��
	}
	ov[s] = ov[e] = false;
	return ol[s][e] + exl;						//(s, e)�̵u���|���@�ǰt �^�Ǩ�P�U�ؤǰt�̤p�Ȫ��M
}
int main() {
	int i, j, x, y, w, exl, sum;
	scanf("%d%d%d", &n, &m, &i);
	for (sum=i=0; i<m; i++) {
		scanf("%d%d%d", &x, &y, &w);
		sum += (map[x][y] = map[y][x] = w);		//��J��ɪ����O���`�M �]�ܤ֨C�䳣�|���@�� ���⦸�H�W�O���F���_�I�q���_�I(�y��_�I�t��B�z)
		side[x]++; side[y]++;					//�O���I�W��
	}
	for (on=i=0; i<=n; i++)
		if (side[i]&1) odd[++on] = i;			//��_�I���K�O�_�I�Ӽ�
	for (i=1; i<=on; i++)
		for (j=i; j<=on; j++)
			ol[i][j] = INFINITY;
	for (int k=1; k<=n; k++)					//�B�� Floyd-Warshall Algorithm �M��_�I���̵u�Z��
		for (i=1; i<=on; i++)
			for (j=1; j<=on; j++)
				if (map[k][ odd[j] ] && ol[i][j] > ol[i][k]+map[k][ odd[j] ])
				ol[i][j] = ol[i][k]+map[k][ odd[j] ];
	if (on)										//�p�G���_�I�s�b �M��U�ؤǰt�̤p��
		for (exl=1<<30,i=2; i<=on; i++)
			exl = min(exl, oddmatch(1, i, on-2));
	else exl = 0;
	printf("%d\n", exl+sum);
}