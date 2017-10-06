class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (NULL == root)
            return;

        queue<TreeLinkNode*> q[2];
        TreeLinkNode* tmp;

        int swt = 0;
        q[swt].push(root);
        while ( !q[0].empty() || !q[1].empty() ) {
            tmp = q[swt].front();
            q[swt].pop();

            if (tmp->left)  q[!swt].push(tmp->left);
            if (tmp->right) q[!swt].push(tmp->right);

            if ( false == q[swt].empty() )
                tmp->next = q[swt].front();
            else
                swt = !swt;
        }
    }
};
