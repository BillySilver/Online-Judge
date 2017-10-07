class Solution {
    int min(int a, int b, int c) {
        return std::min(a, std::min(b, c));
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int **ybar = new int* [matrix.size()];
        int **xbar = new int* [matrix.size()];
        int **mxSquare = new int* [matrix.size()];

        for (int i=0; i < matrix.size(); ++i) {
            ybar[i] = new int[ matrix[i].size() ];
            xbar[i] = new int[ matrix[i].size() ];
            mxSquare[i] = new int[ matrix[i].size() ];

            for (int j=0; j < matrix[i].size(); ++j) {
                if ( '1' == matrix[i][j] ) {
                    if ( 0 == i )
                        ybar[i][j] = 1;
                    else
                        ybar[i][j] = ybar[i-1][j] + 1;

                    if ( 0 == j )
                        xbar[i][j] = 1;
                    else
                        xbar[i][j] = xbar[i][j-1] + 1;

                    if ( 0 == i || 0 == j )
                        mxSquare[i][j] = 1;
                    else
                        mxSquare[i][j] = min(mxSquare[i-1][j-1], ybar[i-1][j], xbar[i][j-1]) + 1;

                    ans = max(ans, mxSquare[i][j]);

                } else {
                    ybar[i][j] = 0;
                    xbar[i][j] = 0;
                    mxSquare[i][j] = 0;
                }
            }
        }

        return ans * ans;
    }
};
