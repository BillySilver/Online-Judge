#include <iostream>
#include <string>
using namespace std;

int main() {
	int map[23][23], n, m, i, j, k, a, b, tc, mtc, min_i, counter=0;
	string name[23];
	while (cin >> n >> m, n+m){
		for (i=1; i<=n; i++) {	
			for (j=1; j<=n; j++)
				map[i][j] = 1000000000;		//��map[1][1]��map[n][n]�w�]�����j��
			map[i][i] = 0;					//��ۮa���Z���k�s
		}
		for (i=1; i<=n; i++)
			cin >> name[i];					//�̧ǿ�J�ܦW�٦C��(name)��
		for (i=1; i<=m; i++) {
			cin >> a >> b >> k;				//��J��a��P��b��H�ήa���Z��(k)
			map[a][b] = map[b][a] = k;		//���V�Z���]�w
		}
		for (k=1; k<=n; k++)				//�T�h�j��۱��|(�Y���L�����֫h�Z���]���̵u������)
			for (i=1; i<=n; i++)
				for (j=1; j<=n; j++)
					map[i][j] = min (map[i][j], map[i][k] + map[k][j]);
		mtc = 1000000000;					//�̤p�`��O�ɶ�(mtc)�w�]�����j��
		for (i=1; i<=n; i++) {
			tc = 0;							//�`��O�ɶ�(tc)�k�s
			for (j=1; j<=n; j++)
				tc += map[i][j];			//���i�a��j�ӤH�һ��`��O�ɶ�
			if (tc < mtc) {
				min_i = i;
				mtc = tc;
			}
		}
		cout << "Case #" << ++counter << " : " << name[min_i] << endl;
	}
}