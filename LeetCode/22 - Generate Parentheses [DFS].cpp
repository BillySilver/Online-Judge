class Solution {
    void gp(int l, int r, string s, vector<string>& ans) {
		if ( 0 > l || 0 > r || l > r )
            return;

        if ( 0 == l && 0 == r ) {
            ans.push_back(s);
            return;
        }

        gp(l-1, r, s+"(", ans);
        gp(l, r-1, s+")", ans);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gp(n, n, "", ans);
        return ans;
    }
};
