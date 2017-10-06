#include <iostream>
#include <algorithm>
using namespace std;
long long h[5005], n, i, cost, s;

void heap(int idx) {
	while (idx!=1)
		if (h[idx>>1] > h[idx]) {
			swap(h[idx>>1], h[idx]);
			idx >>= 1;
		}
		else return;
}

int del() {
	int idx = 1;
	h[0] = h[1];
	h[1] = h[i];
	i--;
	while (idx*2<=i) {
		if (h[idx] > min(h[idx*2], h[idx*2+1])) {
			if (h[idx*2] < h[idx*2+1]) {
				swap(h[idx], h[idx*2]);
				idx *= 2;
			}
			else {
				swap(h[idx], h[idx*2+1]);
				idx = idx*2 + 1;
			}
		}
		else break;
	}
	return h[0];
}

void put(int v) {
	h[++i] = v;
	heap(i);
}

int main() {
	while (scanf("%lld",&n), n) {
		scanf("%lld",&h[1]);
		for (i=2; i<=n; i++) {
			scanf("%lld", &h[i]);
			heap(i);
		}
		cost = 0, i = n;
		while (i>1) {
			s = del() + del();
			cost += s;
			put(s);
		}
		printf("%lld\n",cost);
	}
}