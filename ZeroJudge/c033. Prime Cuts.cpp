#include <iostream>
using namespace std;
int Prime[170]={1}, Primelist[1010], now, i, j, N, C, K;
bool Prime_Table[1010] = {true};
inline void in(int &d) {
	char q;
	while (!isdigit(q=getchar()))
		if(q==-1)break;
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
}

int main() {
	for (i=2; i<1010; i++) {
		if (Prime_Table[i]) continue;
		Prime[(Primelist[i] = ++now)] = i;
		for (j=i*2; j<1010; j+=i) 
			Prime_Table[j] = true;
	}
	for (; in(N),in(C), N; printf("\n")) {
		for (K=0; Prime[K]<=N; K++);
		printf("%d %d:", N, C);
		if (2*C >= K+K%2) C = (K+1)/2;
		for (i=(K+1)/2-C; i<(K+1)/2+C-K%2; i++)
			printf(" %d", Prime[i]);
	}
}