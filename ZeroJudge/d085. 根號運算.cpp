#include <iostream>
long long Prime[78498], PrimeS[78498], now, i, j;
bool Prime_Table[1000001] = {true, true}, cpx;

int main() {
	for (i=2; i<1000001; i++) {
		if (Prime_Table[i]) continue;
		Prime[now] = i;
		PrimeS[now++] = i*i;
		for (j=i*2; j<1000001; j+=i) 
			Prime_Table[j] = true;
	}
	while (scanf("%lld",&now)==1) {
		if (now < 0)
			cpx = true, now = -now;
		else cpx = false;
		for (j=1,i=0; now>=PrimeS[i]; i++) {
			while ( !(now % PrimeS[i]) ) {
				j *= Prime[i];
				now /= PrimeS[i];
			}
		}
		if (j > 1) printf("%lld", j);
		if (now > 1) printf("_/%lld", now);
		if (j==1&&now<2&&!cpx)
			putchar(now ? '1' : '0');
		if (cpx) putchar('i');
		putchar(10);
	}
}