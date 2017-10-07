#include <cstdio>
#include <cctype>   // for isdigit().
#include <algorithm>
#include <cstring>


int c, n, h, i;
char s[16];

inline void in(int &d) {
    char q;
    while (!isdigit(q = getchar()));
    for (d = 0; isdigit(q); q = getchar())
        (d *= 10) += q^48;
}


int main() {
    for (in(c); c--; ) {
        in(n), in(h);
        memset(s, 48, sizeof(s));
        for (i = 0; i < h; i++)
            s[n-i-1] = 49;
        s[n] = 0;
        do puts(s);
        while (std::next_permutation(s, s+n));

        if ( 0 != c )
            putchar(10);
    }
}
