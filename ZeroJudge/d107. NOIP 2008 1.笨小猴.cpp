#include <iostream>
#include <string>
using namespace std;
int ascii[255], mx, mn, ans, i, Prime_Table[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
79, 83, 89, 97};
string s;

int main() {
	while(cin >> s) {
		mx = 0;
		mn = 101;
		memset(ascii, 0, sizeof(ascii));
		for (i=0; i<s.size(); i++) {
			ascii[s[i]]++;
		}
		for (i=97; i<123; i++) {
			mx = max(mx, ascii[i]);
			mn = ascii[i] ? min(mn, ascii[i]) : mn;
		}
		ans = mx-mn;
		for (i=0; i<25&&ans!=Prime_Table[i]; i++);
		if (i!=25)
			printf("Lucky Word\n%d\n", ans);
		else
			printf("No Answer\n0\n");
	}
}