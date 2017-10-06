#include <iostream>
#include <cstdio>
#include <cstring>

int m[10001];

int main() {
    int n, q, qi, prev, now;
    int mx;
    int count = 0;
    while (scanf("%d %d", &n, &q), n*q) {
        printf("CASE# %d:\n", ++count);

        mx = 0;
        memset(m, 0, sizeof(m));

        for (int i = 0; i < n; ++i) {
            scanf("%d", &qi);
            mx = std::max(mx, qi);
            m[qi]++;
        }

        for (int i = 1; i < mx; ++i) {
            m[i] += m[i - 1];
        }

        while (q--) {
            scanf("%d", &qi);

            prev = m[qi - 1];
            now  = m[qi];

            if ( qi > mx || prev == now ) {
                printf("%d not found\n", qi);
            } else {
                printf("%d found at %d\n", qi, prev+1);
            }
        }
    }
}
