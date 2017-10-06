#include <iostream>
using namespace std;
int n, k, bitmask;
bool m[13][13], done[8192]={1,1}, res[8192]={1,0};	//8192 = 2^13, 1 = 先手勝, 0 = 先手輸

bool dp(int star) {
	if (!done[star]) {
		done[star] = true;
		for (int i=0; i<13 && !res[star]; i++)
			for (int j=0; j<13 && !res[star]; j++)
				if (star & (1<<i) && star & (1<<j) && m[i][j])
					res[star] = !dp(star ^ ((1<<i)|(1<<j)));
	}
	return res[star];
}

int main() {
	m[1][2] = m[2][1] = m[2][3] = m[3][2] = m[3][4] = m[4][3] = m[0][2] = m[2][0] = m[0][3] = m[3][0] = true;
	m[5][6] = m[6][5] = m[6][7] = m[7][6] = m[1][5] = m[5][1] = m[2][5] = m[5][2] = m[2][6] = m[6][2] = m[3][6] = m[6][3] = m[3][7] = m[7][3] = m[4][7] = m[7][4] = true;
	m[8][9] = m[9][8] = m[9][10] = m[10][9] = m[10][11] = m[11][10] = m[5][8] = m[8][5] = m[5][9] = m[9][5] = m[6][9] = m[9][6] = m[6][10] = m[10][6] = m[7][10] = m[10][7] = m[7][11] = m[11][7] = true;
	m[9][12] = m[12][9] = m[10][12] = m[12][10] = true;	//相連
	for (int i=0; i<13; i++)
		m[i][i] = true;	//自己和自己也相連
	while (cin >> k) {
		while (k--) {
			cin >> n;
			cout << dp(n) << ' ';
		}
		cout << endl;
	}
}