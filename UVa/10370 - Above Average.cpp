#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int c, n;
    int grade[1000];
    double avg;
    int cnt;
    cin >> c;
    while (c--) {
        cin >> n;
        avg = cnt = 0;
        for (int i = 0; i < n; ++i) {
            cin >> grade[i];
            avg += grade[i];
        }

        avg /= n;
        for (int i = 0; i < n; ++i) {
            if (avg < grade[i])
                cnt++;
        }

        printf("%.3lf%%\n", double(cnt)*100/n);
    }
}
