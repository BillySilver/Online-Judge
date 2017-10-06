#include <iostream>
using namespace std;
unsigned n, m;
int main() {
while (~scanf("%u%u",&n,&m))
printf("%u\n", m+(n!=m));
}