#include <cstdio>
#define abs(a) ((a) > 0 ? (a) : -(a))

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int base, now;
    int d;
    while (scanf("%d", &base), base) {
        scanf("%d", &now);
        d = abs(now - base);
        while (scanf("%d", &now), now)
            d = gcd(d, abs(now - base));
        printf("%d\n", d);
    }
}
