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
			if (done[ f[i][0] ]) {                  //下家將有已知鏈環
				f[i][2] = f[ f[i][0] ][2] + 1;      //包含自己開始的成員數為已知鏈環成員數加一
				continue;
			}
			for (j=i; !done[ f[j][0] ]; j=f[j][0]) { //直到發現未知環or接至已知鏈環
				f[ f[j][0] ][1] = j;                //DFS用, 鏈結上家
				done[ f[j][0] ] = true;
			}
			if (!f[ f[j][0] ][2]) {                 //若下家未計成員數(發現未知環的環頭, j為環尾)
				for (k=f[j][0],m=1; k!=j; k=f[k][0],m++);   //從環頭繞一圈至環尾, 計算環上成員數
				for (k=f[j][0]; k!=j; k=f[k][0])
					f[k][2] = m;                    //環上任意點出發的成員數固定
				f[j][2] = m;						//確定環尾的成員數
				if (f[ f[j][0] ][1]) {				//如果環頭前還有未處理鍊
					for (j=f[ f[j][0] ][1]; f[j][1]; j=f[j][1])	//開始逐步回到最頭, 也就是i
						f[j][2] = f[ f[j][0] ][2] + 1;	//成員數為下家成員數多一
					f[i][2] = f[ f[i][0] ][2] + 1;	//確定頭的成員數
				}
			}
			else {									//若為遇到已知鏈環
				for (; f[j][1]; j=f[j][1])			//開始逐步回到最頭, 也就是i
					f[j][2] = f[ f[j][0] ][2] + 1;	//成員數為下家成員數多一
				f[i][2] = f[ f[i][0] ][2] + 1;		//確定頭的成員數
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
