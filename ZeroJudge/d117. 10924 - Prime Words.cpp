#include <iostream>
#include <math.h>
using namespace std;
int i, j, s, sum;
bool Prime_Table[1041] = {true};

inline void in(int &d) {
	char q;
	while (!isalpha(q=getchar()))
		if (q==-1) break;
	for (d=0; isalpha(q); q=getchar())
		sum += q<=90 ? q-38 : q^96;
}

int main() {
	for (i=2; i<1041; i++) {
		if (Prime_Table[i]) continue;
		for (j=i*2; j<1041; j+=i) 
			Prime_Table[j] = true;
	}
	while (in(sum), sum)
		puts(Prime_Table[sum] ? "It is not a prime word." : "It is a prime word.");
}