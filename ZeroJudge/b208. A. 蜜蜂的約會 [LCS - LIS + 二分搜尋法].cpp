#include <iostream>
using namespace std;
int x[100001], LIS[100002]={-1}, n, i, a, ans;

int bs(int l, int r, int x) {
	int mid = (l+r)>>1;
	if (l >= r) return mid;	
	if (x < LIS[mid]) return bs(l, mid-1, x);
	if (x > LIS[mid]) return bs(mid+1, r, x);
	return mid;
}

int main() {
	while (~scanf("%d", &n)) {
		for (i=0; i<n; i++) {
			scanf("%d", &a);
			x[a] = i;
		}
		for (ans=i=0; i<n; i++) {
			scanf("%d", &a);
			a = x[a];
			if (LIS[ans] < a)
				LIS[++ans] = a;
			else {
				int find = bs(1, ans, a);
				if (LIS[find] < a) LIS[find+1] = a;
				else LIS[find] = a;
			}
		}
		printf("%d\n", ans);
	}
}