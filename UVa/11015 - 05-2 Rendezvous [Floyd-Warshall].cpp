#include <iostream>
#include <string>
using namespace std;


int main() {
    int map[23][23], n, m, i, j, k, a, b, tc, mini, mtc, t = 0;
    string name[23];
    while (cin >> n >> m, n+m){
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++)
                map[i][j] = 1000000000;
            map[i][i] = 0;
        }
        for (i = 1; i <= n; i++)
            cin >> name[i];
        for (i = 1; i <= m; i++) {
            cin >> a >> b >> k;
            map[a][b] = map[b][a] = k;
        }
        for (k = 1; k <= n; k++)
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
        mtc = 1000000000;
        for (i = 1; i <= n; i++) {
            tc = 0;
            for (j = 1; j <= n; j++)
                tc += map[i][j];
            if (mtc > tc) {
                mini = i;
                mtc = tc;
            }
        }
        cout << "Case #" << ++t << " : " << name[mini] << endl;
    }
}
