#include <iostream>
using namespace std;
int k, i, j, fib[45]={1,1};
int main() {
	for (i=2; i<45; i++)
		fib[i] = fib[i-1] + fib[i-2];
	for (; scanf("%d", &k)==1; printf("%d %d\n", fib[i-1], fib[i]))
		for (i=0; k>=fib[i+1]; i++);
}