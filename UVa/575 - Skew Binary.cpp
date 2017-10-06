#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char in[32];
    int sum, size;
    while (cin >> in, '0' != in[0]) {
        sum = 0;
        size = strlen(in);
        for (int i = size - 1; i >= 0; --i)
            sum += (in[i] - '0') * ((1 << size - i) - 1);

        cout << sum << endl;
    }
}
