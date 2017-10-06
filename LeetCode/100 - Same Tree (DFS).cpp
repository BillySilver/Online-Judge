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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ( NULL == p && NULL == q )
            return true;
        else if ( NULL == p || NULL == q )
            return false;

        if ( p->val != q->val )
            return false;

        if ( (NULL == p->left) != (NULL == q->left) )
            return false;

        if ( (NULL == p->right) != (NULL == q->right) )
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
