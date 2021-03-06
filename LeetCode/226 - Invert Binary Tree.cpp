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
    static TreeNode* invertTree(TreeNode* root) {
        if (NULL == root)
            return NULL;

        TreeNode *temp = root->left;
        root->left  = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }
};
