class Solution {

public:
    int findMin(vector<int>& nums) {
        // If the array is rotated, then its front must be greater than its back.
        // Ex: [7 0 1 2 4 5 6] or [1 2 4 5 6 7 0]
        if (nums.front() < nums.back())
            return nums.front();

        int l = 1;
        int r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] < nums[r])
                return nums[l];

            int mid = (l + r) >> 1;

            // The minimum element must not be index 0.
            if ( nums[mid-1] > nums[mid] )
                return nums[mid];

            // Two case:
            // 1. nums[mid] is greater than nums[l], nums[r];
            // 2. nums[mid] is less than nums[l], nums[r].
            if ( nums[l] <= nums[mid] )
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
};
