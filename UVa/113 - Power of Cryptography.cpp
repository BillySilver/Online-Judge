#include <cstdio>
#include <cmath>

int main() {
    double n, p;
    while (~scanf("%lf %lf", &n, &p))
        printf("%.0lf\n", pow(p, 1/n));
}
