#include <iostream>
#include <stdio.h>
#define fibMAX 25
int a[200000], n, k, i, x, m;
int fib[fibMAX]={1, 2};

inline void in(int &d) {
	bool sign = false;
	char q;
	while (!isdigit(q=getchar()))
		if (q=='-') {q=getchar(); sign = true; break;}
	for (d=0; isdigit(q); q=getchar())
		(d*=10) += q^48;
	if (sign) d = -d;
}

int fib_search(int *arr, int fib_i=fibMAX-1, int offset=0) {	// 斐波那契子樹加上總offset才會是在原母樹的編號。
	if (fib_i <= 0)
		return arr[offset+1] == x ? offset+1 : 0;
	int root_i = fib[fib_i] + offset;
	if (root_i > n || x < arr[root_i])	// root_i超過data範圍也要直接往左走
		return fib_search(arr, fib_i-1, offset);
	if (x == arr[root_i])
		return root_i;
	return fib_search(arr, fib_i-2, offset+fib[fib_i]);	// 右子樹的編號減掉根的編號，才會是該費氏子樹的正確編號。
}

int main() {
	for (i=2; i<fibMAX; i++)
		fib[i] = fib[i-1]+fib[i-2];
	in(n), in(k);
	for (i=1; i<=n; i++)
		in(a[i]);
	for (i=0; i<k; i++) {
		in(x);
		printf("%d\n", fib_search(a));
	}
}