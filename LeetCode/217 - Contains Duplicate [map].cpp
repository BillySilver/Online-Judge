class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> appaerance;
        for (int i=0; i < nums.size(); ++i) {
            if (appaerance[ nums[i] ])
                return true;
            appaerance[ nums[i] ] = true;
        }

        return false;
    }
};
