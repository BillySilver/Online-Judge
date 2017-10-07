#include <cstdio>
#include <cctype>   // for isdigit().


int map[101][101];
int T, N, R, u, v, s, d;
int t, c, i, j, k;

inline void in(int &d) {
    char q;
    while (!isdigit(q = getchar()));
    for (d = 0; isdigit(q); q = getchar())
        (d *= 10) += q^48;
}

inline int min(int x, int y) {
    return x < y ? x : y;
}

inline int max(int x, int y) {
    return x > y ? x : y;
}


int main() {
    for (in(T); T--; printf("Case %d: %d\n", ++c, t)) {
        in(N), in(R);
        for (j = 0; j < N; map[j][j++] = 0)
            for (i = 0; i < N; i++)
                map[j][i] = 101;

        while (R--) {
            in(u), in(v);
            map[u][v] = map[v][u] = 1;
        }

        for (k = 0; k < N; k++)
            for (j = 0; j < N; j++)
                for (i = 0; i < N; i++)
                    map[j][i] = min(map[j][i], map[j][k]+map[k][i]);

        in(s), in(d);
        for (t = i = 0; i < N; i++)
            t = max(t, map[s][i]+map[i][d]);
    }
}
