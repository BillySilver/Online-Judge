#include <iostream>
using namespace std;
int l1, b1, d1, l2, b2, d2, damage1, damage2, r;
bool vic;

int main() {
	while (cin >> l1 >> b1 >> d1 >> l2 >> b2 >> d2, l1+b1+d1+l2+b2+d2) {
		damage1 = b2>d1 ? b2-d1 : 0;
		damage2 = b1>d2 ? b1-d2 : 0;
		for (r=0; l1>0&&l2>0; r++) {
			if ((l2-=damage2)<=0) vic = true;
			else if ((l1-=damage1)<=0) vic = false; }		
		printf("You %s in %d round(s).\n", vic?"win":"lose", r);
	}
}