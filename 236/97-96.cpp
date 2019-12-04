#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution
{
public:
	TreeNode *res = NULL;
	int c = 0;
	int dfs(TreeNode *n, TreeNode *p, TreeNode*q)
	{
		if (!n) return 0;
		if (n == p || n == q)
		{
			++c;
			if (c == 2) return 1;
			if (dfs(n->left, p, q) || dfs(n->right, p, q))
			{
				res = n;
				return 2;
			}
			else return 1;
		}
		else
		{
			int t = dfs(n->left, p, q);
			if (t == 2) return 2;
			else if(t==1)
			{
				if (dfs(n->right, p, q))
				{
					res = n;
					return 2;
				}
				else return 1;
			}
			else return dfs(n->right, p, q);
		}
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		dfs(root,p,q);
		return res;
	}
};
int main()
{
	Solution s;

	return 0;
}