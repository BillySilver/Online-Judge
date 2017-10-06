#include <cstdio>
// #include <map>
// #include <deque>
#include <list>
#include <queue>
// #include <cstring>
using namespace std;

int member2team[1000010];

int main() {
    int teamAmt, memberAmt, x;
    char inst[10];
    int cnt = 0;
    // int teamLast[1001];
    int lastX;

    // map<int, int> member2team;
    // deque<int> que;
    // deque<int>::iterator it;
    list< queue<int> > que;
    list< queue<int> >::iterator it;
    queue<int> tempQue;

    while (scanf("%d", &teamAmt), teamAmt) {
        // memset(teamLast, -1, sizeof(teamLast));
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
                // lastX = teamLast[ member2team[x] ];
                // all changed.
                for (it = que.begin(); it != que.end(); ++it) {
                    if ( member2team[ it->front() ] == member2team[x] )
                        break;
                }

                if ( it != que.end() ) {
                    it->push(x);
                } else {
                    tempQue.push(x);
                    que.push_back(tempQue);
                    tempQue.pop();
                }

                // teamLast[ member2team[x] ] = x;
            } else {
                // x = que.front();
                // que.pop_front();
                // if ( x == teamLast[ member2team[x] ] )
                    // teamLast[ member2team[x] ] = -1;
                x = que.front().front();
                que.front().pop();
                if ( que.front().empty() )
                    que.pop_front();

                printf("%d\n", x);
            }
        }
        puts("");
    }
}
