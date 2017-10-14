#include <cstdio>
#include <cstring>


int x[100000];

class BinaryIndexedTree {
    // Range: 1 .. size.
    int size; int *nodes;

    int __lowBit(int idx) {
        return idx & -idx;
    }

public:
    BinaryIndexedTree(int size): size(size) {
        nodes = new int [size+1];
        memset(nodes, 0, sizeof(int)*(size+1));
    }

    ~BinaryIndexedTree() { delete [] nodes; }

    void addIdx(int idx, int delta) {
        while ( idx <= size ) {
            nodes[idx] += delta;
            idx += __lowBit(idx);
        }
    }

    int prefixSum(int idx) {
        int result = 0;
        while ( idx ) {
            result += nodes[idx];
            idx -= __lowBit(idx);
        }
        return result;
    }
};


int main() {
    int n, swaps;
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", x+i);

        swaps = 0;
        BinaryIndexedTree counters(n);
        for (int i = n-1; ~i; --i) {
            swaps += counters.prefixSum( x[i]-1 );  // #swaps for moving 1 .. x[i]-1 located at indices greater than i to the front of x[i].
            counters.addIdx(x[i], 1);
        }

        puts(swaps & 1 ? "Marcelo" : "Carlos");
    }
}
