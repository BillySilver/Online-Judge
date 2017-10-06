#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    char map[101][101];
    int cnt = 0;
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int ny, nx;

    while (cin >> n >> m, n*m) {
        for (int i = 0; i < n; ++i)
            cin >> map[i];

        if (cnt > 0)
            puts("");
        printf("Field #%d:\n", ++cnt);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ('*' == map[i][j])
                    continue;

                map[i][j] = '0';

                for (int k = 0; k < 8; ++k) {
                    ny = i + dy[k];
                    nx = j + dx[k];
                    if ( ny < 0 || nx < 0 || ny == n || nx == m )
                        continue;

                    if ('*' == map[ny][nx])
                        map[i][j]++;
                }
            }
            puts(map[i]);
        }
    }
}
