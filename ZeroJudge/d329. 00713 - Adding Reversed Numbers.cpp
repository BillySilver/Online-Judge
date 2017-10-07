#include <iostream>
using namespace std;
int n, a, b;
inline void in(int &d) {
    int i=1;
    char q;
    while (!isdigit(q=getchar()));
    for (d=0; isdigit(q); q=getchar(),i*=10)
        d += (q^48)*i;
}

int main() {
    scanf("%d",&n);
    while (n--) {
        in(a), in(b);
        a += b;
        for (b=0; a; a/=10)
            (b*=10) += a%10;
        printf("%d\n", b);
    }
}
