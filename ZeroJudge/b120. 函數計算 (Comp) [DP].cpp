#include <iostream>
int gdp[299], hdp[6]={-1,-1,2,5,5,2}, fdp[300+1+89999], i;
/*int g(int z) { //z<=2時會爆高
	if (z <= 2) return z*z - 1; //z=-1,0,1,2用不到可直接省略
	return 2;
}*/
/*int h(int y) { //y<2時都-1
	return y < 2 ? -1 : hdp[y%6];
}*/
/*int f(int x) {
	int hx = x < 2 ? -1 : hdp[x%6]; //hx == h(x);
	if (x < hx) { //x<=-2時成立 x=3,4
		if (fdp[x+300])	return fdp[x+300];
		return fdp[x+300] = f(gdp[x+300]) - gdp[x+300]; //gdp[x+300] == g(x);
	}
	if (x > hx) //x=0,1, x>=5
		return fdp[x+300];
	return fdp[x+300];//x=-1,2
}*/
int main() {
	fdp[300+0] = 2;
	fdp[300+1] = 3;
	fdp[300+2] = fdp[300-1] = 1;
	fdp[300+3] = fdp[300+4] = -1;
	for (i=5; i<90000; i++)
		fdp[i+300] = fdp[i-1+300] - hdp[i%6];
	for (i=-300; i<=-2; i++) {
		gdp[300+i] = i*i-1;
		fdp[300+i] = fdp[300+gdp[300+i]] - gdp[300+i];
	}
	while(~scanf("%d",&i))
		printf("%d\n", fdp[i+300]);
}