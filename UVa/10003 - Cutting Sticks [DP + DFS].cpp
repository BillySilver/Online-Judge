#include <cstdio>
#include <cstring>

int C[52], DP[52][52];


int dp(int idxL, int idxR) {
    int &now = DP[idxL][idxR];
    int tried;
    if ( 0 != now )
        return now;

    for (int i = idxL+1; i < idxR; ++i) {
        tried = dp(idxL, i) + dp(i, idxR) + (C[idxR] - C[idxL]);
        if ( 0 == now || tried < now )
            now = tried;
    }

    return now;
}


int main() {
    int L, N;

    while (scanf("%d", &L), L) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &C[i]);
        // C[0]   = 0;
        C[++N] = L;

        memset(DP, 0, sizeof(DP));
        printf("The minimum cutting is %d.\n", dp(0, N));
    }
}
