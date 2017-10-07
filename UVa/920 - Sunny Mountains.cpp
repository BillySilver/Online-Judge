#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int c, n, i, maxy;
float lp, sum;

struct data {
    float x, y;
} loca[100];

bool cmp(data a, data b) {
    return a.x < b.x;
}


int main() {
    cin >> c;
    while (c--) {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> loca[i].x >> loca[i].y;
        sort(loca, loca+n, cmp);
        for (i = n-1, sum = maxy = 0; i >= 0; i--) {
            if (loca[i].y <= maxy)
                continue;

            lp = (loca[i+1].x - loca[i].x)*(loca[i].y - maxy) / (loca[i].y - loca[i+1].y);
            sum += sqrt((float)(loca[i].y - maxy)*(loca[i].y - maxy) + lp*lp);
            maxy = loca[i].y;
        }
        printf("%.2lf\n", sum);
    }
}
