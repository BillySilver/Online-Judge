#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct exchanging {
    int a, b;
    bool isL2R;

    void set(int loc1, int loc2, bool isLoc1ToLoc2) {
        a = loc1;
        b = loc2;
        isL2R = isLoc1ToLoc2;
    }

    friend bool operator<(exchanging ex1, exchanging ex2) {
        if (ex1.a != ex2.a)
            return ex1.a < ex2.a;
        if (ex1.b != ex2.b)
            return ex1.b < ex2.b;
        return ex1.isL2R == ex2.isL2R;
    }
} info[500000];

int main() {
    int n, a, b;
    while (cin >> n, n) {
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            if (a < b)
                info[i].set(a, b, true);
            else
                info[i].set(b, a, false);
        }
        sort(info, info+n);

        int nowA = -1, nowB = -1, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nowA != info[i].a || nowB != info[i].b) {
                if (0 != cnt) {
                    break;
                } else {
                    nowA = info[i].a;
                    nowB = info[i].b;
                    cnt = 0;
                }
            }

            if (info[i].isL2R)
                cnt++;
            else
                cnt--;
        }

        if (0 == cnt)
            puts("YES");
        else
            puts("NO");
    }
}
