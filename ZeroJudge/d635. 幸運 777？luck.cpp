#include <iostream>
using namespace std;
int n, ans;

int main() {
	while (cin >> n, n>=0) {
		ans = (n & 448)>>6;
		(ans*=10) += (n & 56)>>3;
		(ans*=10) += n & 7;		
		printf("%d\n", ans);
	}
	printf("-1");
}