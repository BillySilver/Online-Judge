#include <iostream>
using namespace std;
int a, b, ans, m, guess, i;
bool AC;
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()))
		if(q==-1) break;
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	while (in(a), in(b), a) {
		ans = max(a, b);
		for (AC=guess=i=0; i<30; i++) {
			in(m);
			if (m) {
				if (guess<3&&m==ans)
					AC=true;
				guess++;
			}
		}
		printf("%c\n", AC ? 'Y' : 'N');
	}
}