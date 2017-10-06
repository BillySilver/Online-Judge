#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string VeryLongIntegerAdd(string a, string b) {
    string &mx = a.size() > b.size() ? a : b;
    string &mn = a.size() > b.size() ? b : a;
    mx.insert(0, 1, '0');

    int mxi, mni;
    for (int i = 0; i < mn.size(); ++i) {
        mxi = mx.size()-1 - i;
        mni = mn.size()-1 - i;

        mx[mxi] += (mn[mni] - '0');
        if ( '9' < mx[mxi] ) {
            mx[mxi] -= 10;
            mx[mxi - 1]++;
        }
    }

    for (mxi = mx.size() - mn.size() - 1; mxi > 0 && '9' < mx[mxi]; --mxi) {
        mx[mxi] -= 10;
        mx[mxi - 1]++;
    }

    if ( '0' == mx[0] )
        mx.erase(0, 1);

    return mx;
}

int main() {
    string sum, now;
    while (cin >> now, "0" != now) {
        sum = VeryLongIntegerAdd(sum, now);
    }
    cout << sum << endl;
}
