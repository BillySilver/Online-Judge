#include <iostream>
#include <algorithm>
using namespace std;


struct number {
    int n, mod;
} a[10000];

bool gt(number a, number b) {
    if (a.mod != b.mod)
        return a.mod < b.mod;
    if ((abs(a.n) % 2) && (abs(b.n) % 2))
        return a.n > b.n;
    if (abs(a.n) % 2 == 0 && abs(b.n) % 2 == 0)
        return b.n > a.n;
    return abs(a.n) % 2;
}


int main() {
    int n, m, i;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            cout << n << ' ' << m << endl;
            break;
        }
        for (i = 0; i < n; i++) {
            cin >> a[i].n ;
            a[i].mod = a[i].n % m;
        }
        sort(a, a+n, gt);
        cout << n << ' ' << m << endl;
        for (i = 0; i < n; i++)
            cout << a[i].n << endl;
    }
}
