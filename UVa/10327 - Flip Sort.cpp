#include <cstdio>
#include <algorithm>

int main() {
    int n, swapping;
    int a[1000];
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        swapping = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n-i; ++j) {
                if (a[j-1] > a[j]) {
                    swapping++;
                    std::swap(a[j-1], a[j]);
                }
            }
        }

        printf("Minimum exchange operations : %d\n", swapping);
    }
}
