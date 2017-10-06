/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* tmp;
        vector<int> ans;
        vector< TreeNode* > stk;
        stk.push_back(root);

        while (!stk.empty()) {
            tmp = stk.back(), stk.pop_back();
            if (NULL == tmp)
                continue;

            ans.push_back(tmp->val);

            stk.push_back(tmp->right);
            stk.push_back(tmp->left);
        }

        return ans;
    }
};
