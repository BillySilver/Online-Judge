#include <iostream>
using namespace std;

int main() {
	int n, i, w, l, mxn;
	float mxl, s;
	while (cin >> n, n){
		mxl =  mxn = 0;
		for (i=1; i<=n; i++){
			cin >> w >> l;
			if (w > l) swap (w, l);
			if (w*4 <= l)
				s = w;
			else if ((float)w/2 > (float)l/4)
				s = (float)w/2;
			else s = (float)l/4;
			if (mxl < s) {
				mxl = s;
				mxn = i;
			}
		}
		cout << mxn << endl;
	}
}