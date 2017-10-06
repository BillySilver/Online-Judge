#include <iostream>
using namespace std;

int main () {
    int n, a, b, c;
	while (cin >> n >> a >> b >> c , n+a+b+c)
		cout << 1080 + 9*((40+n-a)%40) + 9*((40+b-a)%40) + 9*((40+b-c)%40) << endl;
}