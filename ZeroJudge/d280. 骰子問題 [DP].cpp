#include <iostream>
using namespace std;

long long dice[25][157];

long long f(int n, int m) {
	if (dice[n][m+6] == -1)
		return 0;
	else if (dice[n][m+6])
		return dice[n][m+6];
	else if (m < n || m > 6 * n)
		return !(dice[n][m+6] = -1); //!(1) == 0;
	else return dice[n][m+6] = f(n-1, m-1) + f(n-1, m-2) + f(n-1, m-3) + f(n-1, m-4) + f(n-1, m-5) + f(n-1, m-6);
}

int main () {
	int k, n, m, i;
	dice[0][6] = 1;
	for (cin >> k; k--; cout << f(n,m) << endl)
		cin >> n >> m;
}