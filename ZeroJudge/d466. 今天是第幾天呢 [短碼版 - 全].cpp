#include <iostream>
int y,m,d,s[13]={0,31,59,90,120,151,181,212,243,273,304,334,365},B;
int main(){for(;std::cin>>y;scanf("%d%d",&m,&d),B=(!(y%4)&&(y%100))||!(y%400),printf((s[m]-s[m-1]+(B&&m==2)<d||d<1||m>12||m<1||y<1)?"Error\n":"It is %d da%s in %d\n",s[m-1]+d+(B&&m>2),m*d==1?"y":"ys",y));}