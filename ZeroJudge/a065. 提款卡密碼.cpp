//Notepad
#include <iostream>
int i;
char s[8];
int abs(int x) {
return x>0 ? x : -x;
}

int main() {
while (gets(s)) {
for (i=1; i<7; i++)
printf("%d", abs(s[i]-s[i-1]));
puts("");
}
}