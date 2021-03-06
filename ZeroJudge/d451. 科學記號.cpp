#include <iostream>
#include <string>
using namespace std;
inline void Intin (int &d);
inline void Sin(string &d);

int main() {
	int n, dec, i, j, e;
	string s, ans;
	Intin(n);
	while (n--) {
		Sin(s), Intin(j);
		dec = s.find('.');
		if (dec==string::npos) {
			for (i=s.find(','); i!=string::npos && i<s.size(); i+=3)
				s.erase(i,1);
			e = s.size()-1;
			ans.assign(s, 0, j+1);
		}
		else {
			if (s[0]==48) {
				s.erase(1, 1);
				for (i=s.find(','); i!=string::npos && i<s.size(); i+=3)
					s.erase(i,1);
				for (i=0; s[i]==48; i++);
				ans.assign(s, i, i+j);
				e = -i;
			}
			else {
				for (i=s.find(','); i!=string::npos && s[i]==','; i+=3)
					s.erase(i,1);
				e = s.find('.')-1;
				s.erase(e+1, 1);
				for (i=s.find(','); i!=string::npos && s[i]==','; i+=3)
					s.erase(i,1);
				ans.assign(s, 0, j+1);
			}
		}
		if (ans[j]>=53)
			ans[j-1]++;
		for (i=j-1; i>0&&ans[i]>57; i--) {
				ans[i-1]++;
				ans[i]-=10;
		}
		if (ans[0]>57) {
				ans[0]-=10;
				ans.insert(0, 1, '1');
				e++;
			}
		ans.erase(j);
		if (j!=1)
			ans.insert(1, 1, '.');
		printf("%sx10(%d)\n", ans.c_str(), e);
	}
}

inline void Intin (int &d) {
	char ch;
	while (!isdigit(ch=getchar()));
	d = 0;
	do (d *= 10) += ch-'0';
	while (isdigit(ch=getchar()));
}

inline void Sin(string &d) {
	char ch;
	while (ch=getchar(), ch==10||ch==32);
	d = "";
	do d += ch;
	while (ch=getchar(), ch!=10&&ch!=32);
}