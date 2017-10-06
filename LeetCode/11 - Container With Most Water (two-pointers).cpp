class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int mx = 0;
        for (int i=0; i < height.size(); ++i) {
            mx = max(
                mx,
                (r - l) * min(height[l], height[r])
            );
            if ( height[l] < height[r] )
                l++;
            else
                r--;
        }

        return mx;
    }
};
