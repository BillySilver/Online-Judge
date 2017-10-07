#include <cstdio>

int p, e, i, d, ca, ans;


int main() {
    while (scanf("%d %d %d %d", &p, &e, &i, &d), ~d) {
        /*  Chinese Remainder Theorem.
        a:  p       e       i
        n:  23      28      33
        N:  28*33   23*33   23*28   // Product without itself.
            =924    =759    =644
        inv:6       19      2       // Modular multiplicative inverse of N modulo n.
         */

        int const P = 23*28*33;
        // #days (from the beginning of the current year) when t.p. occurs
        ans = ((p * 28*33 * 6) + (e * 23*33 * 19) + (i * 23*28 * 2)) % P;
        // Range: [1, 21252].
        ans = (ans - d - 1 + P) % P + 1;
        printf("Case %d: the next triple peak occurs in %d days.\n", ++ca, ans);
    }
}
