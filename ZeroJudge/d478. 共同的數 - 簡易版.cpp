#include <iostream>
using namespace std;
int n, m, i, j, a[10000], b[10000], ans;

inline void Intin (int &d) {
    char ch;
    while (!isdigit(ch=getchar()));
    d = 0;
    do (d *= 10) += ch-'0';
    while (isdigit(ch=getchar()));
}

int main() {
	cin >> n >> m;
	while (n--) {
		for (i=0; i<m; i++)
			Intin(a[i]);
		for (j=0; j<m; j++)
			Intin(b[j]);
		for (ans=i=j=0; i<m&&j<m; ) {
			if (a[i] > b[j])
				j++;
			else if (a[i] < b[j])
				i++;
			else {
				ans++;
				j++;
				i++;
			}
		}
		printf("%d\n", ans);
	}
}