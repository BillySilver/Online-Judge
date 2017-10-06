#include <iostream>
int T, N, X, Y, M, d;

int main() {
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d%d", &N, &X, &Y, &M);
		printf("%d %d\n", abs(N-Y*M)/abs(X-Y), abs(X*M-N)/abs(X-Y));
	}
}