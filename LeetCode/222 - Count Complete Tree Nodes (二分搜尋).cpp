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
    // Binary search.
    int countNodes(TreeNode* root) {
        if (NULL == root)
            return 0;

        int h, l, r, mid;
        TreeNode* temp = root;

        for (h = 0; temp; ++h)
            temp = temp->left;

        // last level: 0 ~ 2^(h-1)-1 nodes.
        l = 0;
        r = (1 << (h-1)) - 1;
        while (l <= r) {
            mid = (l + r) >> 1;
            temp = root;
            for (int i = h - 2; i >= 0; --i) {
                if ( mid & (1 << i) )
                    temp = temp->right;
                else
                    temp = temp->left;
            }

            if ( NULL == temp )
                r = mid - 1;
            else
                l = mid + 1;
        }

        return (1 << (h-1)) + r;
    }
};
