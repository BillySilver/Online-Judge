#include <cstdio>


int m[7850] = {1}, cent[5] = {1, 5, 10, 25, 50}, i, j, n;

int main() {
    for (i = 0; i < 5; i++)
        for (j = cent[i]; j <= 7489; j++)
            m[j] += m[j-cent[i]];
    while (~scanf("%d", &n))
        printf("%d\n", m[n]);
}
