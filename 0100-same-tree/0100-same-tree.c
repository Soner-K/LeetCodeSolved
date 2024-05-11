/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    char    sameTree;

    sameTree = 1;
    if (!p && !q)
        return (true);
    if (!p && q)
        return (false);
    if (p && !q)
        return (false);
    if (p->val == q->val)
    {
       sameTree *= isSameTree(p->right, q->right);
       sameTree *= isSameTree(p->left, q->left);
    }
    else
        return (false);
    return(sameTree == 1 ? true : false);
}   