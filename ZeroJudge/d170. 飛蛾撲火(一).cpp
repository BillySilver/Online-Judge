#include <iostream>
#include <algorithm>
using namespace std;
int n, x1, y1, x2, y2, x3, y3, i;

inline int abs(int n) {
	return n>=0 ? n : -n;
}

int main() {
	cin >> n;
	while (n--) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		if (x1==x2&&x2==x3)
			if (abs(y1-y3)+abs(y2-y3)==abs(y1-y2))
				printf("該死的東西!竟敢想讓我死！\n");
			else printf("父親大人!母親大人!我快到了！\n");
		else if (y1==y2&&y2==y3)
			if (abs(x1-x3)+abs(x2-x3)==abs(x1-x2))
				printf("該死的東西!竟敢想讓我死！\n");
			else printf("父親大人!母親大人!我快到了！\n");
		else if ((x1-x2)*(y2-y3) == (x2-x3)*(y1-y2) && abs(x3-x1)+abs(x2-x3)==abs(x2-x1))
			printf("該死的東西!竟敢想讓我死！\n");
		else 
			printf("父親大人!母親大人!我快到了！\n");
	}
}