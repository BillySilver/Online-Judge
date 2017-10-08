#include <cstdio>


int main() {
    int n;
    while (scanf("%d", &n), n)
        // sigma(n^2).
        printf("%d\n", n * (n+1) * (2*n+1) / 6);
}
