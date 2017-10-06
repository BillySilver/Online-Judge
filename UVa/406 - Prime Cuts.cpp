#include <iostream>
#include <stdio.h>
using namespace std;
int Prime[170]={1}, Primelist[1010], now, i, j, N, C, K, cas;
bool Prime_Table[1010] = {true};

int main() {
	for (i=2; i<1010; i++) {
		if (Prime_Table[i]) continue;
		Prime[(Primelist[i] = ++now)] = i;
		for (j=i*2; j<1010; j+=i) 
			Prime_Table[j] = true;
	}
	for (; ~scanf("%d%d",&N,&C); puts("\n")) {
		for (K=0; Prime[K]<=N; K++);
		printf("%d %d:", N, C);
		if (2*C >= K+K%2) C = (K+1)/2;
		for (i=(K+1)/2-C; i<(K+1)/2+C-K%2; i++)
			printf(" %d", Prime[i]);
	}
}