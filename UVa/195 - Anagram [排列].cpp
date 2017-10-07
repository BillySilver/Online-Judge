#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int n;
string s;

inline bool rule(int a, int b) {
    if (a >= 65 && a <= 90 && b >= 65 && b <= 90)
        return a < b;
    if (a >= 97 && a <= 122 && b >= 97 && b <= 122)
        return a < b;
    if (a >= 65 && a <= 90)
        return (a - 65 <= b - 97) ? true : false;
    if (a >= 97 && a <= 122)
        return (a - 97 >= b - 65) ? false : true;
}


int main() {
    cin >> n;
    while (n--) {
        cin >> s;
        sort(s.begin(), s.end(), rule);
        do printf("%s\n", s.c_str());
        while (next_permutation(s.begin(), s.end(), rule));
    }
}
