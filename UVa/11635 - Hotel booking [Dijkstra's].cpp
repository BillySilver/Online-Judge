#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


struct Frontier {
    int city, cost;

    Frontier() {}
    Frontier(int c, int t): city(c), cost(t) {}

    bool operator<(const Frontier &rhs) const {
        // Default ordering of priority_queue is descending.
        // So here is a trick to make that the lower cost the higher priority.
        return cost > rhs.cost;
    }
} curr;

struct Edge {
    int successor, cost;

    Edge(int suc, int t): successor(suc), cost(t) {}
};

bool isHotel[10001];
int limit[10001];
vector<Edge> Edges[10001];


int main() {
    int n, h, c, m, a, b, t;
    while (scanf("%d", &n), n) {
        memset(isHotel, 0, sizeof(isHotel));
        memset(limit, 127, sizeof(limit));

        scanf("%d", &h);
        while (h--) {
            scanf("%d", &c);
            isHotel[c] = true;
        }

        scanf("%d", &m);
        while (m--) {
            scanf("%d %d %d", &a, &b, &t);
            Edges[a].push_back( Edge(b, t) );
            Edges[b].push_back( Edge(a, t) );
        }

        // Modified Dijkstra's Algorithm.
        priority_queue<Frontier> q;
        q.push( Frontier(1, 0) );
        limit[1] = 0;
        while (false == q.empty()) {
            curr = q.top();

            // Check if it arrives the destination city.
            if ( n == curr.city )
                break;

            q.pop();

            vector<Edge> &E = Edges[curr.city];
            for (int i = 0; i < E.size(); ++i) {
                b = E[i].successor;
                t = E[i].cost;

                // Check if the driver can arrive City b during the time limit.
                if ( (curr.cost & 1023) + t > 600 )
                    continue;
                c = curr.cost + t;

                // 1. #hotels within new path is less than or equal to the original one's.
                // 2. There is no solution when #hotels = the original one's. We have to relax constraint.
                if ( c < limit[b] || (c & ~1023) > (limit[b] & ~1023) ) {
                    limit[b] = c;
                    q.push( Frontier(b, c) );
                }

                // Try to stay in City b if there is a hotel.
                if ( isHotel[b] ) {
                    c = (curr.cost & ~1023) + 1024;  // Reset the time limit, and increase #hotels.

                    limit[b] = c;
                    q.push( Frontier(b, c) );

                    isHotel[b] = false;              // Without booking twice at the same hotel.
                }
            }
        }

        if ( q.empty() )
            // Solution not found.
            puts("-1");
        else
            printf("%d\n", curr.cost >> 10);

        for (int i = 1; i <= n; ++i)
            Edges[i].clear();
    }
}
