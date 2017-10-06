#include <iostream>
using namespace std;
bool num[58];
int k, i, a, b;
char ans[5], ges[5];

int main () {
	while (cin >> ans >> k)
		for (num[ans[0]]=num[ans[1]]=num[ans[2]]=num[ans[3]]=1; k--; printf("%dA%dB\n", a, b)) {
			scanf("%s", ges);
			for (a=b=i=0; i<4; i++)
				(ges[i]==ans[i]) ? a++ : b+=num[ges[i]];
		}
}