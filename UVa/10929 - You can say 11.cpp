#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int i, d[2];
char s[1001];
int main() {
    while(scanf("%s", s), s[0]!=48||s[1]) {
        for(d[0]=d[1]=i=0; i<strlen(s); i++)
            d[i&1] += s[i]-48;
        printf("%s is%s a multiple of 11.\n", s, (d[0]-d[1])%11 ? " not" : "" );
    }
}

