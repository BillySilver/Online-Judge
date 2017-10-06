#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n, all;

void dfs(int cola, int bottle) {
	if (!cola) {
		if (bottle > 2)
			dfs(bottle/3, bottle%3);
		else if (bottle == 2) all++;
		return;
	}
	all += cola;
	dfs(cola/3, cola%3+bottle);	
}

int main() {
	while (cin >> n) {
		all = 0;
		dfs(n, 0);
		printf("%d\n", all);
	}
}