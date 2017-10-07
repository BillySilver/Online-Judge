#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#define min(a, b) ((a) < (b) ? (a) : (b))

bool map[101][101];
int visit[101];
int low[101];       // Record the deepest back edge of descendants.
int N, cnt;
int step;

void dfs(int parent, int i) {
    visit[i] = low[i] = ++step;

    int child  = 0;
    bool isCut = false;

    for (int j = 1; j <= N; ++j) {
        if ( !map[i][j] || j == parent )    // Excluding the reverse direction of the edge.
            continue;

        if ( visit[j] )                     // Just a back edge.
            low[i] = min(low[i], visit[j]);
        else {                              // Go forward.
            dfs(i, j);
            low[i] = min(low[i], low[j]);

            child++;
            if ( low[j] >= visit[i] )       // j and all of its descendants can't go backword to ancestors of i.
                isCut = true;
        }
    }

    // for the root or internal nodes/leaves.
    if ( i == parent && child > 1 || i != parent && isCut )
        cnt++;
}


int main() {
    int p, p2;
    std::string line;

    while (scanf("%d", &N), N) {
        cnt = 0;
        memset(map, 0, sizeof(map));
        while (scanf("%d", &p), p) {
            std::getline(std::cin, line);
            std::stringstream sin(line);
            while (sin >> p2)
                map[p][p2] = map[p2][p] = true;
        }

        cnt  = 0;
        step = 0;
        memset(visit, 0, sizeof(visit));
        for (int i = 1; i <= N; ++i)
            if ( 0 == visit[i] )
                dfs(i, i);

        printf("%d\n", cnt);
    }
}
