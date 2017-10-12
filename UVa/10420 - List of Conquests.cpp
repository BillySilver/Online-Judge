#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>


int main() {
    int n;
    scanf("%d", &n);
    std::string countries[2000];
    for (int i = 0; i < n; ++i) {
        std::cin >> countries[i];
        while ( '\n' != getchar() );
    }

    std::sort(countries, countries+n);
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if ( countries[i] != countries[i-1] ) {
            printf("%s %d\n", countries[i-1].c_str(), cnt);
            cnt = 0;
        }

        ++cnt;
    }
    printf("%s %d\n", countries[n-1].c_str(), cnt);
}
