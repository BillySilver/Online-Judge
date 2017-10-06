class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (vector<int>::const_iterator it = nums.cbegin(); it < nums.cend(); ++it)
            if ( *it == val )
                nums.erase(it--, it+1);

        return nums.size();
    }
};
