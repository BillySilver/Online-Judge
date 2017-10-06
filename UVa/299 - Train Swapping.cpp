#include <cstdio>
#include <algorithm>

int main() {
    int n, l, swapping;
    int train[50];
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &l);
        for (int i = 0; i < l; ++i)
            scanf("%d", &train[i]);

        swapping = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = 1; j < l-i; ++j) {
                if (train[j-1] > train[j]) {
                    swapping++;
                    std::swap(train[j-1], train[j]);
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", swapping);
    }
}
