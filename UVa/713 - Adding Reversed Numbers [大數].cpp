#include <cstdio>
#include <cstring>


int n, as, bs, cs, i;
char a[201], b[201], c[202];


int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s %s", a, b);
        // Remove suffix zeros.
        for (as = strlen(a); a[as-1] == '0'; --as);
        for (bs = strlen(b); b[bs-1] == '0'; --bs);

        // Adding reversely (from beginning to end).
        c[cs = 0] = 0;
        for (i = 0; i < as && i < bs; ++i) {
            c[cs] += a[i] + b[i] - '0';
            if ( '9' < c[cs] ) {
                c[cs] -= 10;
                c[++cs] = 1;
            } else {
                c[++cs] = 0;
            }
        }

        int &rs = (i < as) ? as : bs;
        char *r = (i < as) ? a  : b;

        // Append remaining digits.
        for ( ; i < rs; ++i) {
            c[cs] += r[i];
            if ( '9' < c[cs] ) {
                c[cs] -= 10;
                c[++cs] = 1;
            } else {
                c[++cs] = 0;
            }
        }
        if ( 0 < c[cs] )
            c[cs++] += '0';

        // Remove prefix zeros.
        for (i = 0; c[i] == '0'; ++i);

        // Output.
        for (; i < cs; ++i)
            putchar(c[i]);
        putchar(10);
    }
}
