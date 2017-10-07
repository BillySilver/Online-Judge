#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    string s;
    int t, i, j, r;
    cin >> t;
    for (getline(cin, s); t--; putchar(10)) {
        getline(cin, s);
        if ( (r = sqrt((float)s.size())) * r == s.size() ) {
            for (i = 0; i < r; i++)
                for (j = i; j < s.size(); j += r)
                    printf("%c", s[j]);
        }
        else printf("INVALID");
    }
}
