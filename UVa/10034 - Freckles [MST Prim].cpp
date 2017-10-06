#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#define N 110
using namespace std;
int n;
double dis[N];
bool use[N];
struct point {
	double x, y;
}P[N];
struct edge {
	int u;
	double w;
	edge () {}
	edge (int u, double w): u(u), w(w) {}
};
vector <edge> E[N]; // edge

inline double distance_p(point x, point y) {
	return sqrt( pow(x.x-y.x, 2.) + pow(x.y-y.y, 2.) );
}

double Prim() {
	int i, j, now, mni;
	double ans = 0, mnd;
	memset(use, 0, sizeof(use));
	for (i=1; i<n; i++)
		dis[i] = 1e30;
	use[now = 0] = true;		//�N�I 0 �m�J�̤p�ͦ���(�|�L��)
	for (j=0; j<n-1; j++) {		//�� n-1 ���䵲��
		for (i=0; i<(int)E[now].size(); i++)	//��s�̤p�ͦ���P��L�D���I���̤p�v��
			dis[E[now][i].u] = min(dis[E[now][i].u], E[now][i].w);
		for (mnd=1e30,i=1; i<n; i++) {			//��X���b��W�B����v���̤p���I
			if (use[i] || mnd <= dis[i]) continue;
			mnd = dis[i];
			mni = i;
		}
		use[now = mni] = true;	//���I�J��
		ans += mnd;				//����J��
	}
	return ans;
}

int main() {
	int i, j, t;
	for (scanf("%d", &t); t--; ) {
		scanf("%d", &n);
		for (i=0; i<n; i++)
			E[i].clear();
		for (i=0; i<n; i++) {
			scanf("%lf%lf", &P[i].x, &P[i].y);
			for (j=0; j<i; j++) {
				E[i].push_back( edge(j, distance_p(P[i], P[j])) );
				E[j].push_back( edge(i, distance_p(P[i], P[j])) );
			}
		}
		printf("%.2lf\n", Prim());
		if (t) puts("");
	}
}