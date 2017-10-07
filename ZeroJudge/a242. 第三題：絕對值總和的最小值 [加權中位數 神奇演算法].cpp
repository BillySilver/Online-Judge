// This code was written on Sep 21 2011 (PCSH Competence Contest).
// But nowaday (2017), I have no idea what the fxxk I wrote.
// However, It is definitely able to be ACCEPTED.


#include <cstdio>
#include <algorithm>
using namespace std;
struct tioj {
    int a, x;
} k[100000];

bool bt(tioj a, tioj b) {
    return a.x < b.x;
}

int main() {
    int m, i, j, mn, down, up, now, n;
    for (scanf("%d", &m); m--; printf("%d\n", mn)) {
        for (i=!scanf("%d", &n); i<n; i++) {
            scanf("%d%d", &k[i].a, &k[i].x);
            k[i].x /= k[i].a;
        }

        sort(k, k+n, bt);
        // Merge duplicate x's.
        for (now=up=down=j=0,i=1; i<n; i++) {
            if (k[j].x == k[i].x) k[j].a += k[i].a;
            else k[++j] = k[i];
        }
        n = j+1;

        for (i=1; i<n; i++) {
            up += k[i].a;
            now += (k[i].x-k[0].x) * k[i].a;
        }
        mn = now;
        for (i=1; i<n; i++) {
            down += k[i-1].a;
            // Now, down + up = sum(a).
            now = now - (k[i].x-k[i-1].x)*(up - down);
            up -= k[i].a;
            mn = min(now, mn);
        }
    }
}
