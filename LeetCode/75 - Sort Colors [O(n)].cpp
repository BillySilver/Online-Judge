class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l, r;
        for (l = 0; l < nums.size() && 0 == nums[l]; ++l);
        for (r = nums.size() - 1; r >= 0 && 2 == nums[r]; --r);

        for (int i = l; i <= r; ++i) {
			if ( 2 == nums[i] ) {
                swap(nums[r], nums[i]);
				while ( r > 0 && 2 == nums[--r] );
			}
            if ( 0 == nums[i] )
                swap(nums[l++], nums[i]);

        }
    }
};
