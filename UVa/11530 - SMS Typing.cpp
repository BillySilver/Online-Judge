#include <stdio.h>
int t, c, sum, acs[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
char q;
int main () {
	for (scanf("%d",&t),getchar(); t--; printf("Case #%d: %d\n", ++c, sum))
		for (sum=0; q=getchar(), q!=10; sum += q==32 ? 1 : acs[q-97]);
}