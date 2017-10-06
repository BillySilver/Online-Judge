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
	use[now = 0] = true;		//將點 0 置入最小生成樹(尚無邊)
	for (j=0; j<n-1; j++) {		//取 n-1 條邊結束
		for (i=0; i<(int)E[now].size(); i++)	//更新最小生成樹與其他非樹點的最小權重
			dis[E[now][i].u] = min(dis[E[now][i].u], E[now][i].w);
		for (mnd=1e30,i=1; i<n; i++) {			//找出不在樹上且對樹權重最小的點
			if (use[i] || mnd <= dis[i]) continue;
			mnd = dis[i];
			mni = i;
		}
		use[now = mni] = true;	//此點入樹
		ans += mnd;				//此邊入樹
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