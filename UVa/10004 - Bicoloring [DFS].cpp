#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool map[200][200];
int color[200];

bool dfs(int s, int n) {
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        if (false == map[s][i])
            continue;

        if (0 != color[i]) {
            if (color[s] == color[i])
                return false;
            else
                continue;
        }

        color[i] = -color[s];
        // printf("%d(%d) -> %d(%d)\n", s, color[s], i, color[i]);
        ans = ans && dfs(i, n);
    }

    return ans;
}

int main() {
    int n, l;
    int a, b;

    while (cin >> n, n) {
        memset(map, 0, sizeof(map));
        memset(color, 0, sizeof(color));

        cin >> l;
        while (l--) {
            cin >> a >> b;
            map[a][b] = map[b][a] = true;
        }

        color[0] = 1;
        if (dfs(0, n))
            puts("BICOLORABLE.");
        else
            puts("NOT BICOLORABLE.");
    }
}
