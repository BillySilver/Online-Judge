#include <stdio.h>
int b, p, m;

int dfs(int a, int e) {
    if (!e) return 1;
    int temp = dfs(a, e/2);
    if (e&1) return (temp*temp%m)*a%m;
    return temp*temp%m;
}

int main() {
	while (~scanf("%d", &b)) {
	    scanf("%d %d", &p, &m);
	    printf("%d\n", dfs(b%m, p));
	}
}
