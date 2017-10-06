#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_P 1000001
using namespace std;

class edge {
 public:
    int idx1, idx2;
    int w;

    friend bool operator<(edge e1, edge e2) {
        return e1.w < e2.w;
    }
};

int father[MAX_P];
class disjointSet {
    int find(int x) {
        return (father[x] == x) ? x : (father[x] = find(father[x]));
    }

 public:
    disjointSet(int size) {
        for (int i = 1; i <= size; ++i)
            father[i] = i;
    }

    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }

    void merge(int x, int y) {
        father[find(x)] = find(y);
    }
};

int Kruskal(vector<edge> &E, int n) {
    disjointSet ds(n);
    int idx1, idx2;
    int cnt = 0;
    int sum = 0;

    sort(E.begin(), E.end());
    for (int i = 0; i < E.size(); ++i) {
        idx1 = E[i].idx1;
        idx2 = E[i].idx2;
        if ( ds.isSameSet(idx1, idx2) )
            continue;

        sum += E[i].w;

        if (++cnt == n-1)
            break;

        ds.merge(idx1, idx2);
    }

    return sum;
}

int main() {
    int t, k, m;
    bool firstCase = true;
    int orgSum;
    vector<edge> E;
    edge tmp;

    while (~scanf("%d", &t)) {
        if (false == firstCase)
            puts("");
        else
            firstCase = false;

        orgSum = 0;
        for (int i = 0; i < t-1; ++i) {
            scanf("%d %d %d", &tmp.idx1, &tmp.idx2, &tmp.w);
            orgSum += tmp.w;
        }
        printf("%d\n", orgSum);

        E.clear();

        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d %d %d", &tmp.idx1, &tmp.idx2, &tmp.w);
            E.push_back(tmp);
        }

        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &tmp.idx1, &tmp.idx2, &tmp.w);
            E.push_back(tmp);
        }

        printf("%d\n", Kruskal(E, t));
    }
}
