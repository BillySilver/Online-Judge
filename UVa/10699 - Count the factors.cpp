#include <iostream>
int P[168], n, i, j, sum;
bool PT[998]={1,1};

int main() {
	for (i=2; i<998; i++)
		if (!PT[i]&&(P[n++]=i))
			for (j=i*i; j<998&&(PT[j]=1); j+=i);
	while (scanf("%d",&n), n) {
		for (j=n,sum=i=0; j!=1&&i<168; i++) {
			if (j%P[i]) continue;
			do j/=P[i];
			while (!(j%P[i]));
			sum++;
		}
		if (j!=1) sum++;
		printf("%d : %d\n", n, sum);
	}
}