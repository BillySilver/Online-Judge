#include <iostream>
using namespace std;
int y, m, d, date[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
bool BY;

int main () {
	for (; cin>>y; scanf("%d%d", &m, &d),BY=(!(y%4)&&(y%100))||!(y%400),(date[m]-date[m-1]+(m==2&&BY)<d||d<1||m>12||m<1||y<1) ? printf("Error\n") : printf("It is %d da%s in %d\n", date[m-1]+d+(BY&&m>2), ((m*d==1)?"y":"ys"), y));
}