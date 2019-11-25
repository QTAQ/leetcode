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
    bool f=false;
    int last=0;
    bool inorder(TreeNode *n){
        if(!n) return true;
        if(!inorder(n->left)) return false;
        if(!f){
            f=true;
            last = n->val;
        }
        else if(n->val<=last) return false;
        else last = n->val;
        if(!inorder(n->right)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return inorder(root);
    }
};