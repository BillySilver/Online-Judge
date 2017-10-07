#include <cstdio>


int T, n, i, hj, lj, last, now, c;


int main() {
    for (scanf("%d", &T); T--; ) {
        scanf("%d %d", &n, &last);
        for (hj = lj = 0, i = 1; i < n; i++) {
            scanf("%d", &now);
            if (now > last)
                hj++;
            else if (now < last)
                lj++;
            last = now;
        }
        printf("Case %d: %d %d\n", ++c, hj, lj);
    }
}
