#include <stdio.h>
int hex[4]={1}, h, i, n, m, b1, b2;

int dtoh(int d) {
    int k;
    for (k=i=0; d; i++)
        k += d%10 * hex[i], d/=10;
    return k;
}

int main() {
    for (i=1; i<4; i++)
        hex[i] = hex[i-1]*16;
    for (scanf("%d",&n); n--; printf("%d %d\n", b1, b2)) {
        scanf("%d", &m);
        b1 = b2 = 0;
        for (i=1<<13; i; i>>=1)
            b1 += !!(m&i);
        m = dtoh(m);
        for (i=1<<15; i; i>>=1)
            b2 += !!(m&i);
    }
}
