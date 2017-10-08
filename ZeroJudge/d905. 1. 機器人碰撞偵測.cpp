#include <cstdio>
#include <string>
#include <algorithm>


std::string map[101][101];
int rob[11][3], n, m, c, x, y, d;
int i, t, remain;
// direction: _, N, NE, E, SE, S, SW, W, NW.
int dx[9] = {2, 0, 1, 1, 1, 0, -1, -1, -1};
int dy[9] = {2, -1, -1, 0, 1, 1, 1, 0, -1};
bool nnc;

inline void freezeRobot(int iRobot) {
    if ( 0 == rob[iRobot][0] )
        return;

    // Set direction to 0.
    rob[iRobot][0] = 0;
    --remain;
}


int main() {
    scanf("%d %d", &n, &m);
    remain = m;
    for (i = 0; i < m; ++i) {
        scanf("%d %d %d %d", &c, &x, &y, &d);
        rob[c][0] = d;
        rob[c][1] = x;
        rob[c][2] = y;
    }

    for (t = 1; remain; ++t) {
        bool isColli[101][101] = {};
        int colliList[10]      = {};
        int nColli             = 0;

        // Update all of robots first.
        for (i = 1; i <= m; ++i) {
            // Ignore frozen robots.
            if ( !rob[i][0] )
                continue;

            x = rob[i][1] + dx[rob[i][0]];
            y = rob[i][2] + dy[rob[i][0]];

            // Check if Robot i reaches the boundaries.
            if (x > n || y > n || x == 0 || y == 0) {
                freezeRobot(i);
                continue;
            }

            // Go forward.
            // We just remove active robots form map in this step.
            // And they will be added back later.
            map[ rob[i][2] ][ rob[i][1] ] = "";
            rob[i][1] = x;
            rob[i][2] = y;
        }

        // Check if collision occurs.
        for (i = 1; i <= m; ++i) {
            // Ignore frozen robots.
            if ( !rob[i][0] )
                continue;

            x = rob[i][1];
            y = rob[i][2];
            std::string &target = map[y][x];

            // Collision occurs!
            if ( 0 != target.size() ) {
                nnc = true;
                // Record the collision point.
                // We should output 1 line at the same t, even more than one robot reaches here.
                // So hold the point, and handle it later.
                if ( false == isColli[y][x] ) {
                    colliList[nColli++] = (y-1)*n + (x-1);
                    isColli[y][x]       = true;
                }

                // Freeze Robot i.
                freezeRobot(i);
                if ( 1 == target.size() )
                    // Freeze the only robot is already at (x, y).
                    freezeRobot(target[0] - 'A');

                // Update robots at target. Sort it later.
                target += i + 'A';
            } else {
                target = i + 'A';
            }
        }


        if ( 0 < nColli ) {
            std::string output[10];
            for (c = 0; c < nColli; ++c) {
                x = colliList[c] % n + 1;
                y = colliList[c] / n + 1;
                std::sort(map[y][x].begin(), map[y][x].end());

                output[c] = map[y][x];
            }

            std::sort(output, output+nColli);
            for (c = 0; c < nColli; ++c) {
                for (i = 0; i < output[c].size(); ++i) {
                    if (i)
                        putchar(' ');
                    printf("%d", output[c][i] - 'A');
                }
                printf(",%d\n", t);
            }
        }
    }

    if (!nnc)
        puts("No collision!");
}
