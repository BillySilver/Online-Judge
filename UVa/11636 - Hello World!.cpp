#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int n, ca = 0;
    while (cin >> n, n >= 0) {
        ca++;
        // log2(n), round up.
        cout << "Case " << ca << ": " << ceil(log10(double(n))/0.30103) << endl;
    }
}
