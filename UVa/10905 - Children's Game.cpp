#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool lp (string a, string b) {
    return a+b < b+a;
}


int main() {
    int n, i;
    string s[50];
    while (cin >> n, n) {
        for (i = 0; i < n; i++)
            cin >> s[i];
        sort (s, s+n, lp);
        for (i = n-1; i >= 0; i--)
            cout << s[i];
        cout << endl;
    }
}
