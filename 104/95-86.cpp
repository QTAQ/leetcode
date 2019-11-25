/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
	int max = 0;
	void dfs(TreeNode* n, int depth)
	{
		if (!n)
		{
			if (depth - 1 > max) max = depth - 1;
			return;
		}
		dfs(n->left, depth + 1);
		dfs(n->right, depth + 1);
	}
	int maxDepth(TreeNode* root)
	{
		if (!root) return 0;
		dfs(root, 1);
		return max;
	}
};