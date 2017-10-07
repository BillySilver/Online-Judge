class Solution {
public:
    // Kadane's Algorithm. (DP)
    int maxSubArray(vector<int>& nums) {
        int dpSum = 0, mx = -1E9;
        for (int i=0; i < nums.size(); ++i) {
            // Choose the latter if dpSum < 0.
            dpSum = max(dpSum + nums[i], nums[i]);
            mx    = max(mx, dpSum);
        }
        return mx;
    }
};
