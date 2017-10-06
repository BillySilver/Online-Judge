#include <iostream>
#include <math.h>
using namespace std;
int Prime[46350], now, i, j, s;
bool Prime_Table[46350] = {true, true}, notprime;

inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	for (i=2; i<46350; i++) {
		if (Prime_Table[i]) continue;
		Prime[now++] = i;
		for (j=i*2; j<46350; j+=i) 
			Prime_Table[j] = true;
	}
	while (in(i), i) {
		if (i > 46350) {
			s = sqrt(float(i));
			for (notprime=j=0; Prime[j]<=s; j++) {
				if (i%Prime[j]) continue;
				notprime = true;
				break;
			}
			puts(notprime ? "1" : "0");
		}
		else puts(Prime_Table[i] ? "1" : "0");
	}
}