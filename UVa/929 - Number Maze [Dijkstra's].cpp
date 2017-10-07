#include <cstdio>
#include <cctype>   // for isdigit().
#include <cstring>
#include <queue>


int t, n, m, map[999][999], i, j;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1}, dr;
bool visit[999][999];

struct data {
    int x, y, sum;
} now, next;

struct cmp {
    bool operator() (data a, data b) {
        return a.sum > b.sum;
    }
};

inline void in(int &d) {
    char q;
    while (!isdigit(q = getchar()));
    for (d = 0; isdigit(q); q = getchar())
        (d *= 10) += q^48;
}


int main() {
    for (in(t); t--; printf("%d\n", now.sum)) {
        in(n), in(m);
        for (j = 0; j < n; j++)
            for (i = 0; i < m; i++)
                in(map[j][i]);

        memset(visit, 0, sizeof(visit));
        now.x = now.y = 0;
        now.sum = map[0][0];
        visit[0][0] = true;
        std::priority_queue <data, std::vector<data>, cmp> q;
        q.push(now);
        while (now = q.top(), !(now.y == n-1 && now.x == m-1)) {
            q.pop();
            for (dr = 0; dr < 4; dr++) {
                i = now.x + dx[dr];
                j = now.y + dy[dr];
                if (i < 0 || j < 0 || i == m || j == n || visit[j][i])
                    continue;

                next.x = i, next.y = j, next.sum = now.sum + map[j][i];
                visit[j][i] = true;
                q.push(next);
            }
        }
    }
}
