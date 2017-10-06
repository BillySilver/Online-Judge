class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target)
            return nums.size();
        if (nums.front() > target)
            return 0;

        int l = 0, r = nums.size()-1;
        int mid;

        while (l < r) {
            mid = (l + r) >> 1;
            if ( target == nums[mid] )
                return mid;

            if ( target < nums[mid] )
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};
