#include <iostream>
using namespace std;
int sudoku[9][9], i, j, sum, a, b;
bool YN;

bool xYN() {
	for (sum=j=0; j<9; j++)
		sum += sudoku[i][j];
	return YN = (sum == 45);
}

bool yYN() {
	for (sum=i=0; i<9; i++)
		sum += sudoku[i][j];
	return YN = (sum == 45);
}

bool squareYN() {
	for (sum=0,i=a; i<a+3; i++)
		for (j=b; j<b+3; j++)
			sum += sudoku[i][j];
	return YN = (sum == 45);
}

int main () {
	while (cin >> sudoku[0][0]) {
		for(j=1; j<9; j++)
			cin >> sudoku[0][j];
		for (i=1; i<9; i++)
			for (j=0; j<9; j++)
				cin >> sudoku[i][j];
		for (i=0; i<9 && xYN(); i++);
		if (YN) {
			for (j=0; j<9 && yYN(); j++);
			for (a=0; YN && a<9; a+=3)
				for (b=0; b<9 && squareYN(); b+=3);
		}
		cout << ((YN) ? "yes\n" : "no\n");
	}
}