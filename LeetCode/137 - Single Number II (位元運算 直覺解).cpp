class Solution {
public:
    // It is a 3-ary operation.
    // ba: 00 -> 01 -> 10 -> 00.
    // The bit of integer which appears 3 times will become to zero (00).
    // However, the bit which comes 1 time will become to one (01). a is the answer consequently.
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int tmp1, tmp2;
        for (int i=0; i<nums.size(); ++i) {
            // tmp1 = (~a & ~b & nums[i]) | (a & ~nums[i]);
            // tmp1 = (~a & ~b & nums[i]) | (a & ~b & ~nums[i]);
            // tmp1 = ~b & (~a & nums[i]) | (a & ~nums[i]);
            tmp1 = ~b & (a ^ nums[i]);
            // tmp2 = (a & ~b & nums[i]) | (b & ~nums[i]);
            tmp2 = (a & nums[i]) | (b & ~nums[i]);
            a = tmp1;
            b = tmp2;
        }

        return a;
    }
};
