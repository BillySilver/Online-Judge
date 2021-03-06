#include <iostream>
using namespace std;
int N, place, L, top, i, q;
struct trie{
	int location[26], num;
}acsii[500000];

void search(char c) {
	if (acsii[L].location[c-97]) 
		L = acsii[L].location[c-97];
	else
		L = acsii[L].location[c-97] = ++place;
}

int main() {
	while (scanf("%d",&N)==1) {
		for (top=place=0; N--; ) {
			while (!isalpha(q=getchar()));
			for (L=i=0; isalpha(q); q=getchar())
				search(q);
			if (!acsii[L].num)
				printf("New! %d\n", acsii[L].num = ++top);
			else
				printf("Old! %d\n", acsii[L].num);
		}
		for (i=0; i<=place; i++) {
			memset(acsii[i].location, 0, sizeof(acsii[i].location));
			acsii[i].num = 0;
		}
	}
}