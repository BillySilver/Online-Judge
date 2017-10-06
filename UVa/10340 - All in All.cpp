#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char s[1000], t[1000];
    int sizeS, sizeT, idxS;
    while (cin >> s >> t) {
        sizeS = strlen(s);
        sizeT = strlen(t);

        idxS = 0;
        for (int i = 0; i < sizeT; ++i) {
            if (s[idxS] == t[i])
                idxS++;

            if (idxS == sizeS)
                break;
        }

        puts((idxS == sizeS) ? "Yes" : "No");
    }
}
