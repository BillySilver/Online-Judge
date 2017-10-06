#include <stdio.h>
#include <string.h>
int temp[2][50], size, now;
char s[11];
bool none;

int digit(int t) {
	int a=10, b=1;
	for (; a<=t; a*=10,b++);
	return b;
}

void put(int t) {
	int i;
	for (i=0,size+=digit(t); t; t/=10,i++)
		temp[0][size-i-1] = t%10;
}

int main() {
	int i, st;
	while (~scanf("%s", s)) {
		for (none=st=1; none&&st<10001; st++) {
			for (size=i=0; s[i]; i++)
				put(s[i]-'A' + st);
			for (now=0; size>3; size--,now=!now) {
				for (i=1; i<size; i++)
					temp[!now][i-1] = (temp[now][i-1] + temp[now][i])%10;
			}
			if (temp[now][0]==1&&!temp[now][1]&&!temp[now][2]) none = false;
		}
		printf(none ? ":(\n" : "%d\n" , st-1);
	}
}
