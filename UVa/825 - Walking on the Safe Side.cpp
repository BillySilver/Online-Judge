#include <iostream>
#include <string>
#include <sstream>
using namespace std;
long long map[101][101];

int main () {
	int input, w, n, i, j, gar;
	string a;
	stringstream ss;
	cin >> input;
	while (input--) {
		cin >> w >> n;
		for (i=1; i<=w; i++)
			for (j=1; j<=n; j++)
				map[i][j] = 1;
		for (i=1; i<=w; i++) {
			cin >> j;
			getline(cin, a);
			ss.clear();
			ss.str(a);
			while (ss >> gar)				
				map[j][gar] = 0;
		}
		map[0][1] = 1;
		for (i=1; i<=w; i++)
			for (j=1; j<=n; j++)
				if (map[i][j])
					map[i][j] = map[i-1][j] + map[i][j-1];
		cout << map[w][n] << endl;
		if (input) cout << endl;
	}
}