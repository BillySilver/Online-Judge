#include <iostream>
#include <string>
using namespace std;
int n, i, num[66];
char c[66];
string s;

inline void Linein(string &d) {
    char ch;
    while (ch=getchar(), ch==10)
		printf("\n");
	memset(num,0,sizeof(num));
	n = 0;
	d = ch==32 ? " " : "";
	if (ch==-1) return;
	do {
		if(ch>=48&&ch<=57)
			num[n]+=ch^48;
		else if(ch=='b')
			c[n++]=32;
		else if(ch=='!') {
			num[n]=1;
			c[n++]=10;
		}
		else 
			c[n++]=ch;
	}
	while (ch=getchar(), ch!=10);
	for (i=0; i<n; i++)
		d.append(num[i], c[i]);
}

int main() {
	while (Linein(s), !s.empty()) {
		printf("%s\n", s.c_str());
	}
}