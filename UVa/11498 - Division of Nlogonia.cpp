#include <cstdio>

int main() {
    int n, ox, oy, x, y;
    while (scanf("%d", &n), n) {
        scanf("%d %d", &ox, &oy);
        while (n--) {
            scanf("%d %d", &x, &y);

            if ( ox == x || oy == y ) {
                puts("divisa");
            } else {
                putchar(oy < y ? 'N' : 'S');
                putchar(ox < x ? 'E' : 'O');
                putchar('\n');
            }
        }
    }
}