#include <iostream>
#include <algorithm>
using namespace std;

bool lp (int a, int b) {
    return abs(a) < abs(b);
}

int f[500000];

int main() {
    int p, n, i, c;
    cin >> p;
    while (p--) {
        cin >> n;
        for (i=0; i<n; i++)
            cin >> f[i];
        sort (f, f+n, lp);
        for (c=i=1; i<n; i++)
            if (f[i-1] > 0 && f[i] < 0 || f[i-1] < 0 && f[i] > 0)
                c++;
        cout << c << endl;
    }
}
