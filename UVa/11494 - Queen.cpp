#include <iostream>
using namespace std;

int main () {
    int X, Y, x, y;
	while (cin >> X >> Y >> x >> y , X+Y+x+y){
		if (X == x && Y == y)
			cout << 0 << endl;
		else
			if (X == x || Y == y)
				cout << 1 << endl;
			else 
				if ( (2 * (max (X,x)) - X - x) == (2 * (max (Y,y)) - Y - y) )
					cout << 1 << endl;
				else
					cout << 2 << endl;
	}
}