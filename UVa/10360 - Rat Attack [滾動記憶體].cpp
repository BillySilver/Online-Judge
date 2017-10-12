#include <cstdio>
#include <cstring>


int map[1025][1025];
int v_sum[1025];

inline int max(int x, int y) {
    return x > y ? x : y;
}



int main() {
    int scenarios, d, n, x, y, i;
    int hv_sum, ans, maxX, maxY;

    scanf("%d", &scenarios);
    while (scenarios--) {
        memset(map, 0, sizeof(map));
        memset(v_sum, 0, sizeof(v_sum));

        scanf("%d %d", &d, &n);
        while (n--) {
            scanf("%d %d %d", &x, &y, &i);
            // It is guaranteed that no position is given more than once.
            // x-major for this problem.
            map[x][y] = i;
        }

        (d <<= 1) |= 1;
        ans = 0;
        for (x = 0; x < 1025; ++x) {
            hv_sum = 0;

            for (y = 0; y < 1025; ++y) {
                v_sum[y] += map[x][y];
                if ( x >= d )
                    v_sum[y] -= map[x-d][y];

                hv_sum += v_sum[y];
                if ( y >= d )
                    hv_sum -= v_sum[y-d];

                if ( ans < hv_sum ) {
                    ans  = hv_sum;
                    maxX = x;
                    maxY = y;
                }
            }
        }

        d >>= 1;
        maxX = max(0, maxX-d);
        maxY = max(0, maxY-d);
        printf("%d %d %d\n", maxX, maxY, ans);
    }
}
