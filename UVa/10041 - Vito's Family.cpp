#include <stdio.h>
#include <algorithm>
using namespace std;
int r, s[500], i, n, d;

int main() {
    for (scanf("%d",&n); n--; printf("%d\n", d)) {
        scanf("%d", &r);
        for (i=0; i<r; i++)
            scanf("%d", &s[i]);
        sort(s, s+r);
        for (d=i=0; i<r; i++)
            d += abs(s[i]-s[r/2]);
    }
}
