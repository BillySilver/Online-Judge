#include <iostream>
int a[7], i, ans, c;

int main() {
	while (scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]), a[1]+a[2]+a[3]+a[4]+a[5]+a[6]) {
		ans = a[6] + a[5] + a[4];
		a[1] -= a[5]*11;	//5 with 1
		a[4] -= a[2]/5;		//4 with 2
		if (a[4] > 0) {
			a[1] -= (20-a[2]%5*4) + (a[4]-1)*20; //4 with 2, 1
			a[2] = 0;
		}
		else// if (a[4] <= 0)
			a[2] -= (a[2]/5 + a[4])*5;
		ans += a[3]/4;
		if (a[3]%4 > 0) {
			if (a[2] >= 7-a[3]%4*2) { // 9*1+4*5+1*7  9*2+4*3+1*6  9*3+4*1+1*5
				a[2] -= 7-a[3]%4*2;
				a[1] -= 8-a[3]%4;
			}
			else {
				a[1] -= (4-a[3]%4)*9 - a[2]*4;
				a[2] = 0;
			}
			ans++;
		} //�ܦ��u��1 2
		if (a[1] < 0) a[1] = 0;
		if (a[2] < 0) a[2] = 0;
		ans += a[2]/9;
		if (a[2]%9) a[1] -= 36 - a[2]%9*4, ans++;
		if (a[1] > 0) ans += (a[1]-1)/36+1;
		printf("%d\n", ans);
	}
}