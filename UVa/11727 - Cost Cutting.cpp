#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int t, sum, mx, mn, gar;
    int cnt = 0;
    cin >> t;
    while (t--) {
        sum = 0;
        mx = 1000;
        mn = 10000;
        for (int i = 0; i < 3; ++i) {
            cin >> gar;
            sum += gar;
            mx = max(mx, gar);
            mn = min(mn, gar);
        }

        printf("Case %d: %d\n", ++cnt, sum-mx-mn);
    }
}
