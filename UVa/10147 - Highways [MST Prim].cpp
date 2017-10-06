#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX_P (750+1)
#define INFINITY 1e30
using namespace std;

class point {
 public:
    int x, y;

    friend double getDis(const point &p1, const point &p2) {
        return sqrt( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) );
    }
};

point pt[MAX_P];
double dis[MAX_P][MAX_P];

double Prim(int n) {
    double sum = 0;
    double MSTOutDis[MAX_P] = {};
    int parent[MAX_P] = {};
    bool isSelected[MAX_P] = {};

    for (int i = 1; i <= n; ++i) {
        MSTOutDis[i] = INFINITY;
        parent[i]    = i;
    }

    // Find (n - 1) edges into the MST.
    // Start from: 1.
    int now = 1, next;
    MSTOutDis[0]    = INFINITY;
    MSTOutDis[now]  = 0;
    isSelected[now] = true;
    for (int e = 0; e < n - 1; ++e) {
        next = 0;
        for (int i = 1; i <= n; ++i) {
            // Check if the point isn't already in the MST.
            if (isSelected[i])
                continue;

            // Update the outgoing edges of the MST.
            if ( dis[now][i] < MSTOutDis[i] ) {
                MSTOutDis[i] = dis[now][i];
                parent[i]    = now;
            }

            // Record the index of the minimum outgoing edge.
            if ( MSTOutDis[i] < MSTOutDis[next] )
                next = i;
        }

        isSelected[next] = true;
        sum += MSTOutDis[next];
        if ( MSTOutDis[next] >= 1 )
            printf("%d %d\n", parent[next], next);

        now = next;
    }
    return sum;
}

int main() {
    int t, n, m;
    int p1, p2;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> pt[i].x >> pt[i].y;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = getDis(pt[i], pt[j]);

        cin >> m;
        while (m--) {
            cin >> p1 >> p2;
            // the cost of existed Highway is ZERO.
            dis[p1][p2] = dis[p2][p1] = 0;
        }

        // Distance of All edges is greater than (or equal to) 1.
        // If no any new Highway needed, the cost of the MST is ZERO.
        if ( Prim(n) < 1 )
            puts("No new highways need");
        if (t > 0)
            puts("");
    }
}
