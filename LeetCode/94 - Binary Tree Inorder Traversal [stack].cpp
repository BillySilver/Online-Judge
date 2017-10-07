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
    class SubTree {
     public:
        TreeNode* root;
        bool isRoot;
        SubTree(TreeNode* root, bool isRoot): root(root), isRoot(isRoot) {};
    };
public:
    vector<int> inorderTraversal(TreeNode* root) {
        SubTree* tmp;
        vector<int> ans;
        vector< SubTree* > stk;
        stk.push_back(new SubTree(root, false));

        while (!stk.empty()) {
            tmp = stk.back(), stk.pop_back();
            if (NULL == tmp->root)
                continue;

            if ( tmp->isRoot )
                ans.push_back(tmp->root->val);
            else {
                stk.push_back( new SubTree(tmp->root->right, false) );
                stk.push_back( new SubTree(tmp->root, true) );
                stk.push_back( new SubTree(tmp->root->left, false) );
            }
        }

        return ans;
    }
};
