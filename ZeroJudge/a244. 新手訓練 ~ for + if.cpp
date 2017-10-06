//Notepad
#include <iostream>
long long n, a, b, c;

int main() {
scanf("%lld",&n);
while (n--) {
scanf("%lld%lld%lld",&a,&b,&c);
if (a==1) b+=c;
if (a==2) b-=c;
if (a==3) b*=c;
if (a==4) b/=c;
printf("%lld\n", b);
}
}