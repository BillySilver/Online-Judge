#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX_P 500
using namespace std;

class point {
    int x, y;

 public:
    void set(int a, int b) {
        x = a;
        y = b;
    }

    friend double getDis(const point &p1, const point &p2) {
        return sqrt( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) );
    }
};

class edge {
 public:
    int idxP1, idxP2;
    double w;

    friend bool operator<(edge e1, edge e2) {
        return e1.w < e2.w;
    }
};

class disjointSet {
    int father[MAX_P];

    int find(int x) {
        return (father[x] == x) ? x : (father[x] = find(father[x]));
    }

 public:
    disjointSet() {
        for (int i = 0; i < MAX_P; ++i)
            father[i] = i;
    }

    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }

    void merge(int x, int y) {
        father[find(x)] = find(y);
    }
};

int s, p;
point pt[MAX_P];
edge E[MAX_P*MAX_P];

double kthMST_Kruskal(const int k) {
    disjointSet ds;
    int idxP1, idxP2;
    int cnt = 0;

    sort(E, E+p*p);
    for (int i = 0; i < p*p; ++i) {
        idxP1 = E[i].idxP1;
        idxP2 = E[i].idxP2;
        if ( ds.isSameSet(idxP1, idxP2) )
            continue;

        if (++cnt == k)
            return E[i].w;

        ds.merge(idxP1, idxP2);
    }

    return -1;
}

int main() {
    int t, x, y;
    cin >> t;
    while (t--) {
        cin >> s >> p;
        for (int i = 0; i < p; ++i) {
            cin >> x >> y;
            pt[i].set(x, y);
        }

        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < p; ++j) {
                E[i*p + j].idxP1 = i;
                E[i*p + j].idxP2 = j;
                E[i*p + j].w     = getDis(pt[i], pt[j]);
            }
        }

        printf("%.2lf\n", kthMST_Kruskal(p - s));
    }
}
