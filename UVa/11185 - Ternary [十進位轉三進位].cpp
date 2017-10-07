#include <iostream>
using namespace std;


int main() {
    int n, i, s[19];
    while (cin >> n, n >= 0) {
        if (n == 0) cout << 0 << endl;
        else {
            for (i = 0; n > 0; i++) {
                s[i] = n % 3;
                n /= 3;
            }
            for (i--; i >= 0; i--)
                cout << s[i];
            cout << endl;
        }
    }
}
