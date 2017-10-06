#include <iostream>
#include <stdio.h>
using namespace std;
int org[3]={0, 2, 1}, bin[9], now[3], mn;
char c[] = {'B','C','G'}, mns[4];
bool use[3];

int gbin(int i, int j) {
	return bin[i*3 + org[j]];
}

void p(int d) {
	int i, j, sum=0;
	if (d == 3) {
		for (i=0; i<3; i++) {
			for (j=0; j<3; j++) {
				if (j == now[i]) continue;
				sum += gbin(i, j);
			}
		}
		if (sum < mn) {
			mn = sum;
			for (i=0; i<3; i++)
				mns[i] = c[now[i]];
		}
		return;
	}
	for (i=0; i<3; i++) {
		if (use[i]) continue;
		use[i] = true;
		now[d] = i;
		p(d+1);
		use[i] = false;
	}
}

int main() {
	int i, j;
	while (~scanf("%d", &bin[0])) {
		for (i=1; i<9; i++)
			scanf("%d", &bin[i]);
		mn = 2147483647;
		p(0);
		printf("%s %d\n", mns, mn);
	}
}