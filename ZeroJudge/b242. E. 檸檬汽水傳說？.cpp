#include <iostream>
#include <deque>
using namespace std;
unsigned long long ans;
int T, n, a, i, j, amn[1000000];
deque<int> A;

int main() {
	for (scanf("%d",&T); T--; printf("%llu\n",ans), A.clear()) {
		for (ans=i=!scanf("%d",&n); i<n; i++) {
			for (scanf("%d",&a); A.size()&&A.back()<a; ans+=amn[A.size()-1], A.pop_back());
			if (j=A.size()-1, ~j&&a==A[j])	//將緊鄰同多全部配對 並加入
				ans+=amn[j]++, j--;
			else amn[A.size()]=1, A.push_back(a);
			if (j>=0&&A[j]>a) ans++;	//次高是否存在 存在便配對
		}
	}
}