#include <cstdio>
// #include <map>
#include <deque>
#include <cstring>
using namespace std;

int member2team[1000010];

int main() {
    int teamAmt, memberAmt, x;
    char inst[10];
    int cnt = 0;
    int teamLast[1001];
    int lastX;

    // map<int, int> member2team;
    deque<int> que;
    deque<int>::iterator it;

    while (scanf("%d", &teamAmt), teamAmt) {
        memset(teamLast, -1, sizeof(teamLast));
        // member2team.clear();
        que.clear();

        printf("Scenario #%d\n", ++cnt);

        for (int i = 0; i < teamAmt; ++i) {
            scanf("%d", &memberAmt);
            for (int j = 0; j < memberAmt; ++j) {
                scanf("%d", &x);
                member2team[x] = i;
            }
        }

        while (scanf("%s", inst), 'S' != inst[0]) {
            if ( 'E' == inst[0] ) {
                scanf("%d", &x);
                lastX = teamLast[ member2team[x] ];
                if ( -1 != lastX ) {
                    for (it = que.begin(); it <= que.end(); ++it) {
                        if ( *it == lastX )
                            break;
                    }

                    que.insert(++it, x);
                } else {
                    que.push_back(x);
                }

                teamLast[ member2team[x] ] = x;
            } else {
                x = que.front();
                que.pop_front();
                if ( x == teamLast[ member2team[x] ] )
                    teamLast[ member2team[x] ] = -1;

                printf("%d\n", x);
            }
        }
        puts("");
    }
}
