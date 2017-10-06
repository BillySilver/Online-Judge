#include <iostream>  
using namespace std;   

int main () {
	long long n, k, r, d, a;
	while (cin >> n >> k) {
		d = 0;
		r = 1;
		while (r) {		//重複直到完全無菸可抽
			a = n;			//本來菸的次數(n都變成菸頭了)
			r = n/k;		//本來菸頭(n)共能做幾個再生菸(f)
			d = n%k;		//本來菸頭(n)做完後所剩菸頭(d)
			while (r) {		//再生菸還有剩
				a = a+r;	//之前抽的次數加再生菸的次數(r都變成菸頭了)
				d = d+r;	//再生菸的菸頭和之前的菸頭
				r = d/k;	//全部菸頭再做成再生菸
				d = d%k;	//又剩下的菸頭
			}
		}
		cout << a << endl;	//
	}
}