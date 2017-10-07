class Solution {
public:
    // Bit Manipulation.
    int majorityElement(vector<int>& nums) {
        int cnt[32] = {}, ans = 0;
        for (int i=0; i < nums.size(); ++i)
            for (int b=0; b < 32; ++b)
                cnt[b] += !!(nums[i] & (1 << b));

        for (int b=31; b >= 0; --b)
            (ans <<= 1) |= (cnt[b] > (nums.size() >> 1));

        return ans;
    }
};
