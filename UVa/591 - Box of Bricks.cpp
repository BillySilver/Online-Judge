#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, h[100], sum, moves;
    int cnt = 0;

    while (cin >> n, n) {
        sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
            sum += h[i];
        }

        sum /= n;
        moves = 0;
        for (int i = 0; i < n; ++i) {
            if ( sum < h[i] )
                moves += h[i] - sum;
        }

        printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++cnt, moves);
    }
}
