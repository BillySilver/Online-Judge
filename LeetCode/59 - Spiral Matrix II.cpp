class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        int cnt = 1;
        int y, x;
        int dy[4] = {0, 1, 0, -1};
        int dx[4] = {1, 0, -1, 0};

        for (int i=0; i < n; ++i) {
            matrix.push_back( vector<int>() );
            for (int j=0; j < n; ++j)
                matrix[i].push_back(0);
        }

        for (int i=0; i < (n >> 1); ++i) {
            y = x = i;
            for (int d=0; d < 4; ++d) {
                for (int j=i; j < n-1-i; ++j) {
                    matrix[y][x] = cnt++;
                    y += dy[d];
                    x += dx[d];
                }
            }
        }
        if ( n & 1 )
            matrix[n >> 1][n >> 1] = cnt;

        return matrix;
    }
};
