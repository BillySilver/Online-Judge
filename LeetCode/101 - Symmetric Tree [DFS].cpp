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
    bool compare(TreeNode *l, TreeNode *r) {
        if ( !l && !r )
            return true;

        if ( !!l ^ !!r )
            return false;

        if ( l->val != r-> val )
            return false;

        return compare(l->left, r->right) && compare(l->right, r->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return (NULL == root) ? true : compare(root->left, root->right);
    }
};
