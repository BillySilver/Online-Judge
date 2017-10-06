#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n;
    int sum;
    puts("PERFECTION OUTPUT");
    while (cin >> n, n) {
        if (n == 1)
            sum = 0;
        else
            sum = 1;

        for (int i = 2; i*i <= n; ++i)
            if ( i*i == n )
                sum += i;
            else if ( 0 == n % i )
                sum += i + n/i;
        printf("%5d  ", n);
        if (sum == n)
            puts("PERFECT");
        else if (sum < n)
            puts("DEFICIENT");
        else
            puts("ABUNDANT");
    }
    puts("END OF OUTPUT");
}
