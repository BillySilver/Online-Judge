#include <cstdio>
#include <cstring>
#include <algorithm>


int AC[101], penalty[101];

inline int max(int a, int b) {
    return a > b ? a : b;
}

bool cmp(int id1, int id2) {
    // the number of problems solved (the more the better).
    if ( AC[id1] != AC[id2] )
        return AC[id1] > AC[id2];

    // decreasing(?) amounts of penalty time. Should it be "increasing"?
    if ( penalty[id1] != penalty[id2] )
        return penalty[id1] < penalty[id2];

    // in order of increasing team numbers.
    return id1 < id2;
}


int main() {
    int cases, id, pid, t;
    char L;
    char buf[101];
    int maxId;
    int WA[101][10];
    int sortedIdx[101];

    scanf("%d  ", &cases);
    while (cases--) {
        maxId = 0;
        memset(AC, -1, sizeof(AC));             // -1 is denoted as non-existent id.
        memset(WA, 0, sizeof(WA));
        memset(penalty, 0, sizeof(penalty));

        while ( NULL != fgets(buf, 101, stdin) && 10 != buf[0] ) {
            sscanf(buf, "%d %d %d %c", &id, &pid, &t, &L);

            maxId = max(maxId, id);
            if ( -1 == AC[id] )                 // had not appeared before.
                AC[id] = 0;

            if ( -1 != WA[id][pid] ) {
                if ( 'C' == L ) {
                    ++AC[id];
                    penalty[id] += 20*WA[id][pid] + t;
                    WA[id][pid] = -1;           // Lock this problem.
                } else if ( 'I' == L ) {        // Only get penalty time at the first correct submission.
                    ++WA[id][pid];
                }
            }
        }

        for (int i = 0; i < maxId; ++i)
            sortedIdx[i] = (i + 1);

        std::sort(sortedIdx, sortedIdx+maxId, cmp);

        for (int i = 0; i < maxId; ++i) {
            int &id_ = sortedIdx[i];
            if ( -1 == AC[id_] )
                break;
            printf("%d %d %d\n", id_, AC[id_], penalty[id_]);
        }

        if (cases)
            putchar(10);
    }
}
