class Solution {
    vector<int> possible;
    bool *choosen;
    void dfs(int n, vector<int>& nums, vector<vector<int>>& ans) {
        if ( 0 == n ) {
            ans.push_back(possible);
            return;
        }

        for (int i=0; i < nums.size(); ++i) {
            if (choosen[i])
                continue;

            choosen[i] = true;
            possible.push_back( nums[i] );
            dfs(n-1, nums, ans);
            possible.pop_back();
            choosen[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        choosen = new bool[nums.size()];
        memset(choosen, 0, sizeof(choosen));
        dfs(nums.size(), nums, ans);
        return ans;
    }
};
