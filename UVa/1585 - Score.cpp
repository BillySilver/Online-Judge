#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, cnt, ans;
    char gar[81];

    cin >> n;
    while (n--) {
        cin >> gar;
        cnt = ans = 0;
        for (int i = 0; i < strlen(gar); ++i) {
            if ('O' == gar[i]) {
                ans += ++cnt;
            } else {
                cnt = 0;
            }
        }

        cout << ans << endl;
    }
}
