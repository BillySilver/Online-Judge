#include <iostream>
int i;
char ans[100000], q;
bool d;

int main() {
	for (i=0; q=getchar(), q!=-1; i++) {
		if (q==34) {
			ans[i] = ans[i+1] = (d=!d) ? 96 : 39;
			i++;
		}
		else ans[i] =  q;
	}
	puts(ans);
}