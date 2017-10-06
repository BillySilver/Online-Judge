#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct data {
	int x, y, step;
}now, next;
bool walked[100][100];
int MoveX[4] = {0, 0, -1, 1}, MoveY[4] = {-1, 1, 0, 0}; //�W�U���k

int main() {
	int N, n, m, StartX, StartY, EndX, EndY, i;
	string map[100];
	cin >> N;
	while (N--) {
		memset(walked, 0, sizeof(walked));		//�}�C�q�Y����k�s
		cin >> n >> m >> StartY >> StartX >> EndY >> EndX;
		for (i=0; i<n; i++)
			cin >> map[i];
		StartX--, StartY--, EndX--, EndY--;		//��X,Y�������W���@(1,1)��(0,0)
		next.x = StartX;
		next.y = StartY;
		next.step = 1;
		queue <data> q;							//�M���s��ƾڥ�
		q.push(next);							//��_�I��i�Ĥ@��
		while (!q.empty()) {					//�P�_q�̭��O���O�ŪŦp�]
			now = q.front();					//����q�̫e�����ƾڮ��X�ӷ��{�b���I
			q.pop();							//�A��q�̫e�����ƾڥᱼ
			if (now.x == EndX && now.y == EndY) break;//�w�g����I�N�X�h
			for (i=0; i<4; i++) {				//�W�U���k�U�]�@��
				next.x = now.x + MoveX[i];
				next.y = now.y + MoveY[i];
				next.step = now.step + 1;
				if (next.x >= m || next.x < 0 || next.y >= n || next.y < 0 || walked[next.x][next.y] || map[next.y][next.x] == '1') continue; //���j������(�X�ɡB���L�B����)
				q.push(next);					//�q�L�W�z���d�ӨS���D��next��iq���̫�
				walked[next.x][next.y] = true;	//�קK���^�Y���������L���a��
			}
		}
		if (now.x == EndX && now.y == EndY)	cout << now.step << endl;//now�O�]�������I�~�X�ӴN��Xnow���B��(�@�w�̵u�A�]���O�̥�����I��)
		else cout << 0 << endl;					//�_�h��X0
	}
}