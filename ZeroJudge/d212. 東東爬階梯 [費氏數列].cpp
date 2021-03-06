#include <iostream>
using namespace std;
long long n, dp[100] = {1,1};

/*inline void dfs(int i) {	//dfs解 幾乎等於費氏數列
	if (i==n) sum++;
	if (i>n) return;
	dfs(i+1);
	dfs(i+2);
}*/

long long fib(long long x){
	if (!dp[x]) {
		return dp[x] = fib(x-1) + fib(x-2);
	}
	else return dp[x];
}

int main() {
	while (cin >> n)
		cout << fib(n) << endl;
}