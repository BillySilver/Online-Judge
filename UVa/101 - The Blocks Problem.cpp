#include <iostream>
#include <string>
using namespace std;
int n, Block[25][25], a, b, i, j, No;
struct location{
	int x, h;
}l[25];
string act1, act2;

int main() {
	while (cin >> n) {
		for (i=0; i<n; i++) {			//�n�쭫�]ing
			for (j=0; j<n; j++)
				Block[i][j] = -1;
			Block[i][0] = i;
			l[i].x = i;
			l[i].h = 0;
		}
		while (cin >> act1) {
			if(act1 == "quit") break;
			cin >> a >> act2 >> b;
			if (l[a].x != l[b].x) {
				if (act1 == "move") {
					for (j=n-1; j>l[a].h; j--)							//�qa�Ҧb�a���n��啕�U��n��(���ʨ�a)
						if (Block[l[a].x][j] >= 0) {
							l[No].x = Block[No][0] = No = Block[l[a].x][j];//�Na�W�����n���^���ç��ܦ�m
							l[No].h = 0;
							Block[l[a].x][j] = -1;						//�N��n���m�B�k�t
						}
				}
				if (act2 == "onto") {
					for (j=n-1; j>l[b].h; j--)							//�qb�Ҧb�a���n��啕�U��n��(���ʨ�b)
						if (Block[l[b].x][j] >= 0) {
							l[No].x = Block[No][0] = No = Block[l[b].x][j];//�Nb�W�����n���^���ç��ܦ�m
							l[No].h = 0;
							Block[l[b].x][j] = -1;						//�N��n���m�B�k�t
						}
				}
				for (j=l[b].h+1; j<n; j++) {							//j�qb���W���@��}�l
					if (Block[l[a].x][l[a].h] < 0) break;				//�qa�쳻�S�n��i���ɸ��X
					if (Block[l[b].x][j] == -1) {						//�p�Gb�Ҧb�n���W������m�i�H��n���
						Block[l[b].x][j] = Block[l[a].x][l[a].h];
						Block[l[a].x][l[a].h++] = -1;					//�Ⲿ�L�h���n���k�t�ñN���ץ[�@
					}
				}
				for (j=1; j<n; j++) {
					if (Block[l[b].x][j] >= 0) {
						l[ Block[l[b].x][j] ].x = l[b].x;	//�Nb�Ҧb�n����ƪ��n���m���]
						l[ Block[l[b].x][j] ].h = j;
					}
					else break;							//b�Ҧb�n�����S�n��ɸ��X
				}
			}
		}
		for (i=0; i<n; i++) {
			cout << i << ":";
			for (j=0; j<n; j++) {
				if (Block[i][j] >= 0) cout << " " << Block[i][j];
				else break;
			}
			cout << endl;
		}
	}
}