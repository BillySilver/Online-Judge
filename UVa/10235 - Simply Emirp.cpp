#include <cstdio>
#include <cctype>   // for isdigit().


int i, j, n, m, k;
bool Prime_Table[1000001] = {true, true};


inline void in(int &d) {
    char q;
    while (!isdigit(q = getchar()))
        if (q == -1) break;
    for (d = 0; isdigit(q); q = getchar())
        (d *= 10) += q^48;
}

int main() {
    for (i = 2; i < 1000001; i++) {
        if (Prime_Table[i])
            continue;

        for (j = i*2; j < 1000001; j += i)
            Prime_Table[j] = true;
    }

    while (in(n), n) {
        if (Prime_Table[n]) {
            printf("%d is not prime.\n", n);
        } else {
            for (m = n, k = 0; m; m /= 10)
                (k *= 10) += m % 10;
            printf("%d is %s.\n", n, !Prime_Table[k] && k != n ? "emirp" : "prime");
        }
    }
}
