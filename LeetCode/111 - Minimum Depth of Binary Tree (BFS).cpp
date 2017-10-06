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
        int dis;

        SubTree(TreeNode* root, int dis): root(root), dis(dis) {};
    };

 public:
    int minDepth(TreeNode* root) {
        if (NULL == root)
            return 0;
        queue< SubTree* > q;
        SubTree* tmp;

        q.push( new SubTree(root, 1) );
        while (!q.empty()) {
            tmp = q.front(), q.pop();

            if ( NULL == tmp->root->left && NULL == tmp->root->right )
                return tmp->dis;

            if ( tmp->root->left )
                q.push( new SubTree(tmp->root->left, tmp->dis+1) );

            if ( tmp->root->right )
                q.push( new SubTree(tmp->root->right, tmp->dis+1) );
        }
    }
};
