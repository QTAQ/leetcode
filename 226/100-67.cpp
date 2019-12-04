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
    TreeNode *invert(TreeNode *n){
        if(!n) return NULL;
        TreeNode *t=n->left;
        n->left = invert(n->right);
        n->right = invert(t);
        return n;
    }
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};