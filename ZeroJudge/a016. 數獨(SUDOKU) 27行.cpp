#include <iostream>
using namespace std;
int sudoku[9][9], i, j, sum, a, b;
bool YN;

bool xyYN() {
	for (sum=j=0; j<9; sum+=((a) ? sudoku[i][j++] : sudoku[j++][i]));		
	return YN = (sum == 45);
}

bool squareYN() {
	for (sum=0,i=a; i<a+3; i++)
		for (j=b; j<b+3; sum += sudoku[i][j++]);
	return YN = (sum == 45);
}

int main () {
	for (; cin >> sudoku[0][0]; printf(YN ? "yes\n" : "no\n")) {
		for(YN=j=1; j<9; scanf("%d", &sudoku[0][j++]));
		for (i=1; i<9; i++)
			for (j=0; j<9; scanf("%d", &sudoku[i][j++]));
		for (a=0; YN && a<2; a++)
			for (i=0; i<9 && xyYN(); i++);
		for (a=0; YN && a<9; a+=3)
			for (b=0; b<9 && squareYN(); b+=3);
	}
}