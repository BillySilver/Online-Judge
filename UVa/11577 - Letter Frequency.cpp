#include <cstdio>
#include <cstring>


int T, acsii[27], mx, i;

inline int max(int x, int y) {
    return x > y ? x : y;
}

inline void in() {
    char q;
    while (q = getchar(), (q < 65 || q > 90) && (q < 97 || q > 122));
    for (; q != 10; q = getchar())
        if (q >= 65 && q <= 90)
            acsii[q^64]++;
        else if (q >= 97 && q <= 122)
            acsii[q-96]++;
}


int main() {
    for (scanf("%d", &T); T--; ) {
        memset(acsii, 0, sizeof(acsii));
        in();
        for (mx=i=1; i < 27; i++)
            mx = max(acsii[i], mx);
        for (i = 1; i < 27; i++)
            if (mx == acsii[i])
                printf("%c", i+96);
        puts("");
    }
}
