#include <iostream>
using namespace std;
int T, n, i, hj, lj, last, now, c;

int main() {
    for (cin>>T; T--; ){
        cin >> n >> last;
        for (hj=lj=0,i=1; i<n; i++) {
            cin >> now;
            if(now>last) hj++;
            else if(now<last) lj++;
            last = now;
        }
        printf("Case %d: %d %d\n", ++c, hj, lj);
    }
}
