#include <iostream>
int P[4792], n, i, j;
bool PT[46341]={1,1};	//0為質數，1為合數

int main() {
	for (i=2; i<46341; i++)
		if (!PT[i]&&(P[n++]=i))
			for (j=i*i; j<46341&&(PT[j]=1); j+=i);
	while (scanf("%d",&n), n) {
		printf("%d = ", n);
		if (n < 0) {
			i = 0;
			n = -n;
			printf("-1");
		}
		else {
			for (i=0; i<4792&&n%P[i]; i++);
			if (i==4792) {
				printf("%d\n", n);
				continue;
			}
			printf("%d", P[i]);
			while (!((n/=P[i])%P[i]))
				printf(" x %d", P[i]);
		}
		for (; n!=1&&i<4792; i++) {
			if (n%P[i]) continue;
			printf(" x %d", P[i]);
			while (!((n/=P[i])%P[i]))
				printf(" x %d", P[i]);
		}
		if (n!=1) printf(" x %d\n", n);
		else putchar(10);
	}
}