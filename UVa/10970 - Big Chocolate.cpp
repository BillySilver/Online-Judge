#include <iostream>
int i, thr, e[2], y;
char s[1000];
bool now, ok;

int main() {
	while (~(s[0]=getchar())) {
		thr = e[0] = s[0]^48;
		ok = e[1] = 0;
		for (now=i=1; (s[i]=getchar())!=10; i++) {
			thr += s[i]^48;
			e[now] += s[i]^48;
			now = !now;
		}
		y = (s[i-1]^48) + (s[i-2]^48)*10 + (s[i-3]^48)*100 + (s[i-4]^48)*1000;
		if ( !(y%4) && y%100 || !(y%400) ) {
			puts("This is leap year.");
			ok = 1;
		}
		if ( !(thr%3) && !(y%5) ) {
			puts("This is huluculu festival year.");
			ok = 1;
		}
		if ( ( !(y%4) && y%100 || !(y%400) ) && (!(abs(e[0] - e[1])%11) && !(y%5)) ) {
			puts("This is bulukulu festival year.");
			ok = 1;
		}
		if (!ok) puts("This is an ordinary year.");
		puts("");
	}
}