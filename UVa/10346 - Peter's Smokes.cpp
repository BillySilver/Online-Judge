#include <iostream>  
using namespace std;   

int main () {
	long long n, k, r, d, a;
	while (cin >> n >> k) {
		d = 0;
		r = 1;
		while (r) {		//���ƪ��짹���L�ҥi��
			a = n;			//���ӵҪ�����(n���ܦ����Y�F)
			r = n/k;		//���ӵ��Y(n)�@�వ�X�ӦA�͵�(f)
			d = n%k;		//���ӵ��Y(n)������ҳѵ��Y(d)
			while (r) {		//�A�͵��٦���
				a = a+r;	//���e�⪺���ƥ[�A�͵Ҫ�����(r���ܦ����Y�F)
				d = d+r;	//�A�͵Ҫ����Y�M���e�����Y
				r = d/k;	//�������Y�A�����A�͵�
				d = d%k;	//�S�ѤU�����Y
			}
		}
		cout << a << endl;	//
	}
}