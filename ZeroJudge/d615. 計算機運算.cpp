#include <iostream>
long long t, sum, now, i;
char s[1000000], oper;

int main() {
	for (scanf("%lld",&t),getchar(); t--; ) {
		gets(s);
		for (sum=now=i=0; s[i]; i++) {
			if (s[i]==32) continue;
			if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') {
				oper = s[i];
				i++;
				break;
			}
			(sum *= 10) += s[i]^48;
		}
		for (; s[i]; i++) {
			if (s[i]==32) continue;
			if (isdigit(s[i])) {
				(now *= 10) += s[i]^48;
				continue;
			}
			if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') {
				if (oper=='+')
					sum += now, now=0;
				else if (oper=='-')
					sum -= now, now=0;
				else if (oper=='*')
					sum *= now, now=0;
				else if (oper=='/')
					sum /= now, now=0;
				oper = s[i];
			}
		}
		if (oper=='+')
			sum += now, now=0;
		else if (oper=='-')
			sum -= now, now=0;
		else if (oper=='*')
			sum *= now, now=0;
		else if (oper=='/')
			sum /= now, now=0;
		printf("%lld\n", sum);
	}
}