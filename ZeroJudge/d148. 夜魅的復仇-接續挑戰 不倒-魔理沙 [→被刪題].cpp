#include <iostream>
using namespace std;

int main() {
	char q;
	for(q=getchar(); q!=-1; q=getchar())
		if (isalpha(q)) printf("%c", q);
}