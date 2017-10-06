#include <cstdio>
#include <algorithm>
#define int64 long long

int main() {
    int n, m, k;
    int p[501];
    int l;
    int64 r;
    int64 mid, cnt, sum;
    int posSlash[501];
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &m, &k);

        l = r = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d", &p[i]);
            l = std::max(l, p[i]);
            r += p[i];
        }

        // find the minimized maximum scriber page P with greedy.
        // default possible interval (of P) is [max(p), sigma(p)].
        // l is the infimum of possible interval.
        // r is the supermum of possible interval.
        // use binary search in possible interval.
        while (l < r) {
            mid = (l >> 1) + (r >> 1);
            cnt = 0;
            sum = 0;

            // counting the minimum number of scribers when P = mid.
            for (int i = 0; i < m; ++i) {
                if ( mid < sum + p[i] ) {
                    cnt++;
                    sum = p[i];
                    if ( k == cnt )
                        break;
                } else {
                    sum += p[i];
                }
            }

            // success.
            if ( k - 1 >= cnt ) {
                r = mid;
            // failure.
            } else {
                l = mid + 1;
            }
        }

        // find where the slash in.
        // distribute reversely to minimize the 1st (2nd, 3rd...) scriber.
        // k scribers <=> k-1 slashes.
        sum = 0;
        cnt = 0;
        for (int i = m-1; i >= 0; --i) {
            if ( l < sum + p[i] ) {
                cnt++;
                sum = p[i];
                posSlash[k - cnt] = i;
                if ( k - 1 == cnt )
                    break;
            } else {
                sum += p[i];
            }

            // remaining slashes is not less than remaining books.
            // then distributes them one to one.
            if ( k - 1 - cnt == i ) {
                for (int j = 0; j < i; ++j)
                    posSlash[j+1] = j;
                break;
            }
        }

        cnt = 1;
        for (int i = 0; i < m; ++i) {
            if (i > 0)
                putchar(' ');

            printf("%d", p[i]);

            if (cnt < k && posSlash[cnt] == i) {
                printf(" /");
                cnt++;
            }
        }
        puts("");
    }
}
