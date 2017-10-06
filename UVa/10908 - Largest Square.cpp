#include <cstdio>

int main() {
    const int dy[4] = {0, -1, 0, 1};
    const int dx[4] = {-1, 0, 1, 0};
    int t, m, n, q;
    int x, y;
    int nx, ny, radius;
    char map[100][100];

    scanf("%d", &t), getchar();
    while (t--) {
        scanf("%d %d %d", &m, &n, &q), getchar();
        printf("%d %d %d\n", m, n, q);

        for (int i = 0; i < m; ++i) {
            scanf("%s", map[i]), getchar();
        }

        while (q--) {
            scanf("%d %d", &y, &x, &q), getchar();

            for (radius = 1; ; ++radius) {
                ny = y + radius;
                nx = x + radius;
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < (radius << 1); ++j) {
                        ny += dy[i];
                        nx += dx[i];

                        if ( ny < 0 || nx < 0 || ny >= m || nx >= n )
                            goto DONE;
                        if ( map[ny][nx] != map[y][x] )
                            goto DONE;
                    }
                }
            }
DONE:
            printf("%d\n", 2 * radius - 1);
        }
    }
}
