class Solution {
public:
    // DP.
    int numTrees(int n) {
        int *dp = new int[n+1];
        dp[0] = 1;
        for (int i=1; i <= n; ++i) {
            dp[i] = (i & 1) ? (dp[i>>1] * dp[i>>1]) : 0;
            for (int j=0; j < (i>>1); j++)
                dp[i] += (dp[j] * dp[i-j-1]) << 1;
        }
        return dp[n];
    }
};
