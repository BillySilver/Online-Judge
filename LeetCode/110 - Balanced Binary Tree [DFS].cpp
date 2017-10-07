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
    int height(TreeNode* root) {
        if (NULL == root)
            return 0;

        int hl = height(root->left);
        if ( -1 == hl ) return -1;
        int hr = height(root->right);
        if ( -1 == hr ) return -1;

        if ( abs(hl - hr) > 1 )
            return -1;

        return max(hl, hr) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return -1 != height(root);
    }
};
