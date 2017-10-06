/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    void connectInner(TreeLinkNode *root, TreeLinkNode *neighbor) {
        if (NULL == root)
            return;

        root->next = neighbor;

        connectInner(root->left, root->right);
        connectInner(root->right, neighbor ? neighbor->left : NULL);
    }

public:
    void connect(TreeLinkNode *root) {
        connectInner(root, NULL);
    }
};
