#include <iostream>
#include <string>
using namespace std;
int int32, s[10], i, d;
bool zero;
//char num[21]("零壹貳參肆伍陸柒捌玖");
string num[10] = {"零","壹","貳","參","肆","伍","陸","柒","捌","玖"};
//cout << num[i*2] << num[i*2+1];

int main() {
	while (cin >> int32) {
		for (zero=i=0; int32; i++) {
			s[i] = int32%10;
			int32 /= 10;
		}
		d = i;
		for (--i; i>=0; i--) {
			if (s[i]) {
				if (zero) printf("零");
//				printf("%c%c", num[s[i]*2], num[s[i]*2+1]);
				cout << num[s[i]];
				if (i%4 == 3) {
					printf("仟");
					zero = false;
				}
				if (i%4 == 2) {
					printf("佰");
					zero = false;
				}
				if (i%4 == 1) {
					printf("拾");
					zero = false;
				}
			}
			else zero = true;
			if (!(i%4) && i) {
				(i==8) ? printf("億") : printf("萬");
				zero = false;
			}
		}
		printf("\n");
	}
}
