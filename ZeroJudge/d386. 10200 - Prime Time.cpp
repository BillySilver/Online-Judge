#include <iostream>
#include <math.h>
int Euler[10002]={0, 1}, Prime[78498], i, j, n, e;
bool Prime_Table[1000001] = {true, true};

int main() {
    for (i=2; i<1000001; i++) {
        if (Prime_Table[i]) continue;
        Prime[n++] = i;
        for (j=i*2; j<1000001; j+=i)
            Prime_Table[j] = true;
    }
    for (n=1; n<10001; n++)
        if ((e = n*(n+1)+41) > 1000000) {
            j = sqrt(float(e));
            for (i=0; Prime[i]<=j&&e%Prime[i]; i++);
            Euler[n+1] = Euler[n] + (Prime[i]>j);
        }
        else
            Euler[n+1] = Euler[n] + !Prime_Table[e];
    while (~scanf("%d%d",&n,&e)) {
        if (n==e) puts(Euler[e+1]-Euler[n] ? "100.00" : "0.00");
        else {
            n = (Euler[e+1] - Euler[n]) * 100000 / (e + 1 - n);
            if (n%10 > 4) n += 10;
            printf("%d.", (n/=10)/100);
            n %= 100;
            putchar((n/10)|48), putchar((n%10)|48), putchar(10);
        }
    }
}
