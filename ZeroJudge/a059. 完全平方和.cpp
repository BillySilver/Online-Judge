//Notepad
#include <iostream>
#include <cmath>
int i, t, a, b;

int main() {
scanf("%d",&t);
for (i=1; i<=t; i++) {
scanf("%d%d",&a,&b);
printf("Case %d: %d\n", i, (b=sqrt((float)b))*(b+1)*(2*b+1)/6 - (a=sqrt((float)a-1))*(a+1)*(2*a+1)/6);
}
}