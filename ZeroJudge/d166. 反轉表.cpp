#include <iostream>
using namespace std;
int a[51], i, n, m, j;

int main () {
	for (; cin>>a[1], a[1]>=0; putchar(10)) {
		for (m=2; cin.peek()!=10; cin>>a[m++]);
		for (j=1; j++<m; printf("%d ", i))
			for (i=1; a[i]--; i++);
	}
}