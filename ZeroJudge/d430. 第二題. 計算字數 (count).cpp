#include <iostream>
int n;

inline bool isSymb(int a) {
	return a==',' || a=='.' || a=='?' || a=='!' || a==' ' || a==10;
}
inline bool isWord(int a) {
	return a>=48&&a<=57 || a>=65&&a<=90 || a>=97&&a<=122;
}

int main() {
	for (char p=0,q=getchar(); q!=-1; p=q,q=getchar())
		if (isWord(p)&&isSymb(q)) n++;
	printf("%d",n);
}
