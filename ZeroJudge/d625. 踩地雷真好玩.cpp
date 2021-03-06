#include <iostream>
#include <string>
using namespace std;
int n, i, j, k, x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, y[8] = {0, 1, 1, 1, 0, -1, -1, -1}, delay;
string map[100];

int main() {
	while (cin >> n) {
		for (j=0; j<n; j++) {
			cin >> map[j];
		}
		for (j=0; j<n; j++) {
			for (i=0; i<n; i++) {
				if (map[j][i] == '*') continue;
				for (delay=k=0; k<8; k++) {
					if (j+y[k] < 0 || i+x[k] < 0 || j+y[k] >= n || i+x[k] >= n) continue;
					if (map[j+y[k]][i+x[k]] == '*') delay++;
				}
				if (delay) map[j][i] = delay + '0';
			}
		}
		for (j=0; j<n; j++)
			cout << map[j] << endl;
	}
}