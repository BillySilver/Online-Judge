#include <iostream>
#include <string>
using namespace std;


int main() {
    string n;
    int i, s, t, d;
    while (cin >> n, n != "0") {
        s = 0;
        for (i = 0; i < n.size(); i++)          // 求所有位數的數字和
            s += n[i] - '0';

        if (s % 9)                              // 不是 9 的倍數
            cout << n << " is not a multiple of 9.\n";
        else {
            for (d = 1; s > 9; d++)             // d(egree)
                for (t = s, s = 0; t; t /= 10)  // 求 t 的數字和
                    s += t % 10;

            cout << n << " is a multiple of 9 and has 9-degree " << d << ".\n";
        }
    }
}
