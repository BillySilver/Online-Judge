//Notepad
#include <iostream>
#include <string>
using namespace std;
int i, n;
string s[10];
char a[10];

int main() {
s[0] = "BNZ";
s[1] = "AMW";
s[2] = "KLY";
s[3] = "JVX";
s[4] = "HU";
s[5] = "GT";
s[6] = "FS";
s[7] = "ER";
s[8] = "DOQ";
s[9] = "CIP";
while (gets(a)) {
for (n=a[8]^48,i=0; i<8; i++)
n += (a[i]^48)*(8-i);
printf("%s\n", s[(10-n%10)%10].c_str());
}
}