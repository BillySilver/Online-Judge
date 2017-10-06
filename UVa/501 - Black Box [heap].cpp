#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
    int k, m, n;
    int a, get, i;

    cin >> k;
    while (k--) {
        queue<int> add;

        cin >> m >> n;
        for (int j = 0; j < m; ++j) {
            cin >> a;
            add.push(a);
        }

        priority_queue< int, vector< int >, greater<int> > min_heap;
        priority_queue< int, vector< int >, less<int> > max_heap;
        cin >> get;
        i = 0;
        for (int j = 1; j <= m; ++j) {
            a = add.front(), add.pop();

            if ( false == max_heap.empty() && a < max_heap.top() ) {
                max_heap.push(a);

                a = max_heap.top(), max_heap.pop();
            }
            min_heap.push(a);

            while (get == j) {
                a = min_heap.top(), min_heap.pop();
                cout << a << endl;
                max_heap.push(a);

                if ( n == ++i )
                    goto DONE;

                cin >> get;
            }
        }
        DONE:

        if (k != 0)
            cout << endl;
    }
}
