#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define N 110
using namespace std;
int father[N], n;
struct point {
	double x, y;
}P[N];
struct edge {
	int v, u;
	double w;
	edge () {}
	edge (int v, int u, double w): v(v), u(u), w(w) {}
};
vector <edge> E; // edge

int find(int x) {
	return (father[x] == x) ? x : (father[x] = find(father[x]));
}

inline bool cmp(edge left, edge right) {
	if (left.w == right.w)
		if (left.v == right.v)
			return left.u < right.u;
		else
			return left.v < right.v;
	return left.w < right.w;
}

inline double distance_p(point x, point y) {
	return sqrt( pow(x.x-y.x, 2.) + pow(x.y-y.y, 2.) );
}

double Kruskal() {
	int i, j, vhd, uhd;
	double ans = 0;
	for (i=0; i<n; i++)		//�U�I�@���X
		father[i] = i;
	sort(E.begin(), E.end(), cmp);	//���v�Ѥp�Ƨ�
	for (i=j=0; i<(int)E.size()&&j<n-1; i++) {	//�� n-1 ���䵲��
		vhd = find(E[i].v), uhd = find(E[i].u);
		if (vhd != uhd) {		//���b�P�ӳs�q���q
			father[vhd] = uhd;	//�X�ֳs�q���q
			ans += E[i].w;		//�����s�q���q�����A�]�O�̤p�ͦ�����
			j++;				//�����w�[�J���X���I��
		}
	}
	return ans;
}

int main() {
	int i, j, t;
	for (scanf("%d", &t); t--; ) {
		scanf("%d", &n);
		E.clear();
		for (i=0; i<n; i++) {
			scanf("%lf%lf", &P[i].x, &P[i].y);
			for (j=0; j<i; j++)
				E.push_back( edge(i, j, distance_p(P[i], P[j])) );
		}
		printf("%.2lf\n", Kruskal());
		if (t) puts("");
	}
}