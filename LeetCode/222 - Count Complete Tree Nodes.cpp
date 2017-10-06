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
    // Find "perfect binary subtrees".
    int countNodes(TreeNode* root) {
        if (NULL == root)
            return 0;

        TreeNode* temp;
        int lh, rh;

        temp = root;
        for (lh = 0; temp; ++lh)
            temp = temp->left;

        temp = root;
        for (rh = 0; temp; ++rh)
            temp = temp->right;

        // isPerfect.
        if ( lh == rh )
            return pow(2, lh) - 1;

        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};
