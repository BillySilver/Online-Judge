#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int m[10001];

int main() {
    int n, q, qi, p;
    int count = 0;
    while (cin >> n >> q, n*q) {
        printf("CASE# %d:\n", ++count);
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
        }

        sort(m, m+n);

        while (q--) {
            cin >> qi;
            for (p = 0; p < n; p++) {
                if ( qi == m[p] )
                    break;
            }

            if ( n == p ) {
                printf("%d not found\n", qi);
            } else {
                printf("%d found at %d\n", qi, p+1);
            }
        }
    }
}
