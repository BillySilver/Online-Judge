#include <stdio.h>
#include <string.h>
int t, cs, n, mx, mxn, f[50001][3], i, j, k, m; //0:next 1:last 2:member
bool done[50001];

int main() {
	for (scanf("%d",&t); cs<t; printf("Case %d: %d\n", ++cs, mxn)) {
		scanf("%d",&n);
		memset(f, 0, sizeof(f));
		memset(done, 0, sizeof(done));
		for (i=0; i<n; i++)
			scanf("%d", &j), scanf("%d", &f[j][0]);
		for (i=1; i<=n; i++) {                      //DFS
			if (done[i]) continue;
			done[i] = true;
			if (done[ f[i][0] ]) {                  //�U�a�N���w������
				f[i][2] = f[ f[i][0] ][2] + 1;      //�]�t�ۤv�}�l�������Ƭ��w�����������ƥ[�@
				continue;
			}
			for (j=i; !done[ f[j][0] ]; j=f[j][0]) { //����o�{������or���ܤw������
				f[ f[j][0] ][1] = j;                //DFS��, �쵲�W�a
				done[ f[j][0] ] = true;
			}
			if (!f[ f[j][0] ][2]) {                 //�Y�U�a���p������(�o�{�����������Y, j������)
				for (k=f[j][0],m=1; k!=j; k=f[k][0],m++);   //�q���Y¶�@�������, �p�����W������
				for (k=f[j][0]; k!=j; k=f[k][0])
					f[k][2] = m;                    //���W���N�I�X�o�������ƩT�w
				f[j][2] = m;						//�T�w������������
				if (f[ f[j][0] ][1]) {				//�p�G���Y�e�٦����B�z��
					for (j=f[ f[j][0] ][1]; f[j][1]; j=f[j][1])	//�}�l�v�B�^����Y, �]�N�Oi
						f[j][2] = f[ f[j][0] ][2] + 1;	//�����Ƭ��U�a�����Ʀh�@
					f[i][2] = f[ f[i][0] ][2] + 1;	//�T�w�Y��������
				}
			}
			else {									//�Y���J��w������
				for (; f[j][1]; j=f[j][1])			//�}�l�v�B�^����Y, �]�N�Oi
					f[j][2] = f[ f[j][0] ][2] + 1;	//�����Ƭ��U�a�����Ʀh�@
				f[i][2] = f[ f[i][0] ][2] + 1;		//�T�w�Y��������
			}
		}
		for (mx=mxn=i=1; i<=n; i++) {
			if (f[i][2] > mx) {
				mx = f[i][2];
				mxn = i;
			}
		}
	}
}
