#include <iostream>
using namespace std;
int i, j, N;
bool Prime_Table[1000001] = {true, true};
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()));
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	for (i=2; i<1000001; i++) {
		if (Prime_Table[i]) continue;
		for (j=i*2; j<1000001; j+=i) 
			Prime_Table[j] = true;
	}
	while(in(N), N)
		puts(Prime_Table[N] ? "1" : "0");
}