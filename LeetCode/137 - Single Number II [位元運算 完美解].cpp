class Solution {
public:
    // It is a 3-ary operation.
    // ba: 00 -> 01 -> 10 -> 00.
    // The bit of integer which appears 3 times will become to zero (00).
    // However, the bit which comes 1 time will become to one (01). a is the answer consequently.
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for (int i=0; i<nums.size(); ++i) {
            // It is a very pertty solution.
            // a = 0 -> 1 -> 0 -> 0
            //        / |  / |  / |   using NOT, XOR.
            //       /  v /  v /  v   100, 100, 100, ...
            // b = 0 -> 0 -> 1 -> 0
            a ^= ~b & nums[i];
            b ^= ~a & nums[i];
        }

        return a;
    }
};
