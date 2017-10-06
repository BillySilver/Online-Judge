class Solution {
    unsigned toA(int y, int x)  {
        return y + x;
    }

    unsigned toB(int y, int x, int n) {
        return (n - 1 - y) + x;
    }

    bool *setX, *slantA, *slantB;
    int dfs(int y, int n) {
        if (-1 == y)
            return 1;

        int ans = 0;
        for (int x = 0; x < n; ++x) {
            if ( setX[x] || slantA[toA(y, x)] || slantB[toB(y, x, n)] )
                continue;

             setX[x] = slantA[toA(y, x)] = slantB[toB(y, x, n)] = true;
             ans += dfs(y-1, n);
             setX[x] = slantA[toA(y, x)] = slantB[toB(y, x, n)] = false;
        }

        return ans;
    }

public:
    int totalNQueens(int n) {
        setX = new bool[n];
        slantA = new bool[(n<<1)-1];
        slantB = new bool[(n<<1)-1];
        memset(setX, 0, n);
        memset(slantA, 0, (n<<1)-1);
        memset(slantB, 0, (n<<1)-1);

        return dfs(n - 1, n);
    }
};
