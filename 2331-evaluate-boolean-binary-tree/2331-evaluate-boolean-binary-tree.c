/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define OR 2
#define AND 3

bool evaluateTree(struct TreeNode* root) {
    if (!root)
        return (false);
    if (root->val == true)
        return (true);
    else if (root->val == false)
        return (false);
    else if (root->val == OR)
        return (evaluateTree(root->right) || evaluateTree(root->left));
    else
        return (evaluateTree(root->right) && evaluateTree(root->left));
    return (false);
}



