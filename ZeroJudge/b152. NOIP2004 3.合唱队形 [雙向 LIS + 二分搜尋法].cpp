#include <iostream>
using namespace std;
int t[100], LISque[101]={-1}, LIS[100], LDS[100], tail;

int bs(int *arr, int l, int r, int x) {
	int mid = (l+r)>>1;
	if (l >= r) return mid;	
	if (x < arr[mid]) return bs(arr, l, mid-1, x);
	if (x > arr[mid]) return bs(arr, mid+1, r, x);
	return mid;
}

int nowLIS(int x) {
	if (LISque[tail] < x)
		LISque[++tail] = x;
	else {
		int find = bs(LISque, 1, tail, x);
		if (LISque[find] < x) LISque[find+1] = x;
		else LISque[find] = x;
	}
	return tail;
}

int main() {
	int i, n, mx=0;
	scanf("%d", &n);
	for (tail=i=0; i<n; i++) {
		scanf("%d", &t[i]);
		LIS[i] = nowLIS(t[i]);
	}
	for (tail=!(i=n-1); ~i; i--) {
		LDS[i] = nowLIS(t[i]);
		mx = max(mx, LIS[i]+LDS[i]);
	}
	printf("%d\n", n-mx+1);
}