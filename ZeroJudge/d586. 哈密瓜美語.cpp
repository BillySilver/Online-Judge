#include <iostream>
using namespace std;
int n, ascii[123], i, m, sum, d;
char ai[]="uzrmatifxopnhwvbslekycqjgd", ia[]=" mjqhofawcpnsexdkvgtzblryui";

int main() {
	char q;
	for (i=0; i<26; i++)
		ascii[ai[i]] = i+1;
	while (q=getchar(),q==10||q==32);
	for (n=0; isdigit(q); q=getchar())
		(n*=10) += q^48;
	while (n--) {
		while (q=getchar(),q==10||q==32);
		for (m=0; isdigit(q); q=getchar())
			(m*=10) += q^48;
		while (q=getchar(),q==10||q==32);
		if (isdigit(q)) {
			for (d=0; isdigit(q); q=getchar())
				(d*=10) += q^48;
			printf("%c", ia[d]);
			for (i=1; i<m; i++) {
				while (q=getchar(),q==32);
				for (d=0; isdigit(q); q=getchar())
					(d*=10) += q^48;
				printf("%c", ia[d]);
			}
		}
		else {
			for (sum=i=0; i<m; i++) {
				sum += ascii[q];
				while (q=getchar(),q==32);
			}
			printf("%d", sum);
		}
		puts("");
	}
}