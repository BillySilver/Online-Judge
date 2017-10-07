class Solution {
public:
    // Boyer-Moore Majority Vote Algorithm.
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ans = 0;
        for (int i=0; i < nums.size(); ++i) {
            if ( ans == nums[i] )
                cnt++;
            else {
                if ( 0 < cnt )
                    cnt--;
                else {
                    cnt = 1;
                    ans = nums[i];
                }
            }
        }

        return ans;
    }
};
