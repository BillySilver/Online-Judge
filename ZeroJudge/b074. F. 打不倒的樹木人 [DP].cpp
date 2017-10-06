#include <iostream>
using namespace std;
unsigned dp[10001]={1,1}, n;
char s[10001];

int main() {
	while (gets(s), s[0]-48) {
		for (int i=2; i<strlen(s)+1; i++) {
			if (s[i-1]=='0')
				dp[i] = dp[i-2];
			else if (s[i-2]=='1'|| (s[i-2]=='2'&&s[i-1]<='6'))
				dp[i] = dp[i-2] + dp[i-1];
			else dp[i] = dp[i-1];
		}
		printf("%u\n", dp[strlen(s)]);
	}
}