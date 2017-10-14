#include <cstdio>
#include <cstdio>
#include <cstring>


int cent[256];
char buf[10001];


int main() {
    int n, k, m, money;
    unsigned char c;

    scanf("%d", &n);
    while (n--) {
        money = 0;
        memset(cent, 0, sizeof(cent));

        scanf("%d ", &k);
        while (k--) {
            scanf("%d ", cent+getchar());
        }

        scanf("%d ", &m);
        while (m--) {
            // gets(buf);               // gets will let you get a CE.
            fgets(buf, 10000, stdin);
            for (int i = 0; buf[i]; ++i)
                money += cent[ buf[i] ];
        }

        printf("%.2f$\n", (double)money / 100);
    }
}
