#include <cstdio>

int C[52], DP[52][52];


int main() {
    int L, N;

    while (scanf("%d", &L), L) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &C[i]);
        // C[0]   = 0;
        C[++N] = L;

        for (int gap = 2; gap <= N; ++gap) {
            // Search intervals [0][gap] .. [N-gap][N].
            // [0][1], [1][2], ..., [N-1][N] should always be zeros,
            // and it is not neccessary to initialize them.
            for (int idxR = gap; idxR <= N; ++idxR) {
                int idxL = idxR - gap;

                int &now = DP[idxL][idxR];
                int tried;

                now = 1<<20;
                for (int cut = idxL+1; cut < idxR; ++cut) {
                    tried = DP[idxL][cut] + DP[cut][idxR] + (C[idxR] - C[idxL]);
                    if ( tried < now )
                        now = tried;
                }
            }
        }

        printf("The minimum cutting is %d.\n", DP[0][N]);
    }
}
