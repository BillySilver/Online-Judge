class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(grid);

        for (int i=0; i < m; ++i) {
            // j = 0
            if ( 0 < i )
                dp[i][0] += dp[i-1][0];
            // j in [1, n)
            for (int j=1; j < n; ++j) {
                if ( 0 < i )
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                else
                    dp[i][j] += dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
