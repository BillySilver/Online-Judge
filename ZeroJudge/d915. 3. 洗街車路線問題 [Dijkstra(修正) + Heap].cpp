#include <iostream>
#include <stdio.h>
using namespace std;

struct emt {							//�������A(�i�ۭq)
	int w, e;
	friend bool compare(emt a, emt b) {	//����禡(�i�ۭq)
		return a.w < b.w;
	}
	friend void swap(emt &a, emt &b) {	//�洫�禡
		emt temp = a;
		a = b, b = temp;
	}
};

struct heap {
	short length;						//heap ���ثe�j�p
	emt node[5001];						//heap �j�p(�i�ۭq)
	void push(emt p) {					//������J heap
		short l = ++this->length;
		emt *nd = this->node;
		nd[l] = p;
		while (l-1 && compare(nd[l], nd[l/2])) {
			swap(nd[l], nd[l/2]);
			l /= 2;
		}
	}
	emt root() {						//heap ������
		return this->node[1];
	}
	void pop() {						//�N heap �����ȥ��A�ýվ� heap
		short &l = this->length;
		emt *nd = this->node;
		nd[1] = nd[l];
		l--;
		short pa=1, sn=2;
		while (sn <= l && (compare(nd[sn], nd[pa]) || compare(nd[sn+1], nd[pa]))) {
			if (compare(nd[sn], nd[sn+1])) {
				swap(nd[pa], nd[sn]);
				sn = (pa=sn) << 1;
			}
			else {
				swap(nd[pa], nd[sn+1]);
				sn = (pa=sn+1) << 1;
			}
		}
	}
	emt take() {						//���� heap ������
		emt temp = root();
		pop();
		return temp;
	}
};

int map[1501][1501], side[1501], odd[15], ol[15][15], n, m, on;	//map�����v side�O���I�W�� odd�O���_�I�y�� ol���U�_�I���̵u���| on���_�I��
bool ov[15];			//ov�O���w�t��_�I(�_�I�t���)

int dijkstra(int s, int e) {
	int i, j;
	bool visited[1501] = {};	//���F�u�ơA�Y�Y�I�w�g�Q���X�L�A��ܤ��᪺���|�����|�A��u(�j�󵥩�)�A��O���ABranch
	emt now, next;
	heap h;
	now.e = s;
	now.w = 0;
	h.push(now);
	while (1) {
		now = h.take();
		visited[now.e] = true;					//�s�W����G�z�LHeap��F���I�֩w�O�w�z�L�̵u���|�~��F�A�]���O���U�ӡA���Ӥ��A���X
		if (now.e == e) return now.w;			//�p�G�ثeheap���v���̤p�����|�̲׬O�q�����I �t��k����
		for (j=1; j<=n; j++) {					//�M��"���X�����|���I"�ਫ����
			if (!visited[j] && map[now.e][j]) {	//*�P����������P�A�o�̱ư��w�g���X�L���I�A�]���o�غt��k���|�A���Z�������|Relaxing
				next.e = j;
				next.w = now.w + map[now.e][j];
				h.push(next);
			}
		}
	}
}


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
	for (i=1; i<=on; i++)						//�B�� Dijkstra's algorithm �M��_�I���̵u�Z��
		for (j=i+1; j<=on; j++)
			ol[i][j] = ol[j][i] = dijkstra(odd[i], odd[j]);
	if (on)										//�p�G���_�I�s�b �M��U�ؤǰt�̤p��
		for (exl=1<<30,i=2; i<=on; i++)
			exl = min(exl, oddmatch(1, i, on-2));
	else exl = 0;
	printf("%d\n", exl+sum);
}