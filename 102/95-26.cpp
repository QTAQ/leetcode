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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		if (!root) return {};
		vector<vector<int>> res;
		deque<TreeNode*> ctl(1, root);
		deque<TreeNode*> ntl;
		vector<int> ctlnum;
		while (!ctl.empty())
		{
			TreeNode* n = ctl.front();
			if (n->left) ntl.push_back(n->left);
			if (n->right) ntl.push_back(n->right);
			ctlnum.push_back(n->val);
			ctl.pop_front();
			if (ctl.empty())
			{
				res.push_back(ctlnum);
				ctlnum.clear();
				ctl = ntl;
				ntl.clear();
			}
		}
		return res;
	}
};