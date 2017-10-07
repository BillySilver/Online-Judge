#include <iostream>
using namespace std;


int main() {
    int s, a[12], i, ca = 1, r;
    while (cin >> s, s >= 0) {
        for (i = 0; i < 12; i++)
            cin >> a[i];
        cout << "Case " << ca++ << ":\n";
        for (i = 0; i < 12; i++) {
            cin >> r;
            cout << "No problem";
            if (s >= r) {
                cout << "! :D\n";
                s -= r;
            } else {
                cout << ". :(\n";
            }
            s += a[i];
        }
    }
}
