#include <cstdio>
#include <cctype>   // for isdigit().


unsigned a, l, t, c, n;

inline bool in(unsigned &d) {
    char q;
    while (!isdigit(q = getchar()))
        if (q == '-')
            return false;
    for (d = 0; isdigit(q); q = getchar())
        (d *= 10) += q^48;
    return true;
}


int main() {
    while (in(n)) {
        in(l);
        for (a = n, t = 1; a != 1; t++) {
            a = (a & 1) ? (3 * a + 1) : a / 2;
            if (a > l)
                break;
        }
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n", ++c, n, l, t);
    }
}
