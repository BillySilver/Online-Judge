#include <cstdio>
#include <cctype>   // for isdigit().


inline int gcd(int a, int b) {
    return (a %= b) ? gcd(b, a) : b;
}

inline void Binary(int &n) {
    char ch;
    while (!isdigit(ch = getchar()));
    n = 0;
    do n = n*2 + ch-48;
    while (isdigit(ch = getchar()));
}


int main() {
    int n, a, b, c;
    for (scanf("%d", &n), c = 1; n--; c++) {
        Binary(a), Binary(b);
        printf("Pair #%d: %s!\n", c, (gcd(a, b) == 1) ? "Love is not all you need" : "All you need is love");
    }
}
