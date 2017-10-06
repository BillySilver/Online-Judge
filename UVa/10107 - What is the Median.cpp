#include <iostream>
using namespace std;
int a[10000], i, j, n;

void insert(int m) {
	a[i] = m;
	for (j=i; a[j]<a[j-1]; j--)
		swap(a[j], a[j-1]);
}

int main () {
	scanf("%d", &a[0]);
	printf("%d\n", a[0]);
	for (i=1; cin>>n; i++) {
		insert(n);
		printf("%d\n", ( (i%2) ? (a[(i-1)/2]+a[(i+1)/2])/2 : a[i/2] ));
	}
}