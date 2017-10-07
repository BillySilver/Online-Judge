#include <iostream>
int n, i, j, g;
inline void in(int &d) {
    char q;
    while (!isdigit(q=getchar()));
    for (d=0; isdigit(q); q=getchar())
        (d*=10) += q^48;
}
inline int gcd(int x, int y) {
    return (x%=y) ? gcd(y, x) : y;
}

int main() {
    while (in(n), n) {
        g = 0;
        for(i=1; i<n; i++)
            for(j=i+1; j<=n; j++)
                g += gcd(i,j);
        printf("%d\n", g);
    }
}
