#include <stdio.h>
int see;
int n, dptop[20]={1, 4, 8}, bot_i=2, size=7;
long long dp[1000001] = {0, 0, 1, 8, 11, 69, 88, 96}, digit[20]={1};

void make(int top, int bot, bool zero=false) {
	if (size == 1000000)
		return;
	if (!zero)
		for (int i=dptop[bot_i-2]; i<dptop[bot_i-1]&&size<1000000; i++)
			dp[++size] = (long long)top*digit[bot_i] + dp[i]*10 + bot;
	else {
		if (bot_i & 1) //b00q
			dp[++size] = top*digit[bot_i] + bot;
		for (int j=bot_i&1; j<=bot_i-4; j+=2) //b0~0q ¤Ö4¦ì
			for (int i=dptop[j]; i<dptop[j+1]&&size<1000000; i++)
				see = dp[++size] = top*digit[bot_i] + dp[i]*digit[bot_i/2 - j/2] + bot;
	}
}

int main() {
	for (n=1; n<20; n++)
		digit[n] = digit[n-1]*10;
	while (bot_i<19) {
		make(1, 1, true);
		make(1, 1);
		make(6, 9, true);
		make(6, 9);
		make(8, 8, true);
		make(8, 8);
		make(9, 6, true);
		make(9, 6);
		dptop[++bot_i] = size+1;
	}
	while (scanf("%d", &n), n)
		printf("%lld\n", dp[n]);
}