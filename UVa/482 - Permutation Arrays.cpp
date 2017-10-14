#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#define SIZE 10000


using namespace std;


int main() {
    int cases;
    int p_inv[SIZE], n, i;
    string x[SIZE], line;

    scanf("%d ", &cases);
    while (cases--) {
        getline(cin, line);
        stringstream sin(line);

        for (n = 0; sin >> i; ++n)
            p_inv[i] = n;
        for (i = 0; i < n; ++i)
            cin >> x[i];

        for (i = 1; i <= n; ++i)
            puts(x[ p_inv[i] ].c_str());

        getchar(), getchar();   // To ignore 2 EOL characters.

        if ( cases )
            putchar(10);
    }
}
