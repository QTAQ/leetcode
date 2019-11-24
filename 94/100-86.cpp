class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<TreeNode*> stk;
		vector<int> res;
		TreeNode *n = root;
		while (true)
		{
			while (n)
			{
				stk.push_back(n);
				n = n->left;
			}
			if (stk.empty()) break;
			n = stk.back();
			res.push_back(n->val);
			n = n->right;
			stk.pop_back();
		}
		return res;
	}
};