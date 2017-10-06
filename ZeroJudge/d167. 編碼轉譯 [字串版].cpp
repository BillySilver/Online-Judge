#include <iostream>
#include <string>
using namespace std;
int acsii, i, now;
char q;
string s;

int main() {
	while(q=getchar(), q!=-1) {
		s = "___________\n";
		for (s+=10; q!=10; q=getchar()) {
			s += '|';
			for (i=7; i>2; i--)
				s += (q & 1<<i) ? 'o' : ' ';
			for (s+='.'; i>=0; i--)
				s += (q & 1<<i) ? 'o' : ' ';
			(s += '|') += 10;
		}
		s += "|    o. o |\n___________";
		puts(s.c_str());
	}
}