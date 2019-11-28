
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
typedef TreeNode n;
class Solution
{
public:
	int max = INT32_MIN;
	int dfs(TreeNode *n)
	{
		if (!n) return 0;
		int l = dfs(n->left);
		l = (l > 0) ? l : 0;
		int r = dfs(n->right);
		r = (r > 0) ? r: 0;
		if (n->val + l + r > max) max = n->val + l + r;
		return (n->val + ((l > r) ? l : r));
	}
	int maxPathSum(TreeNode* root)
	{
		dfs(root);
		return max;
	}
};
int main()
{
	Solution s;
	n a(1); n b(2); n c(3); n d(1); n e(3); n f(-2); n g(-1);
	a.left = &b; 
	a.right = &c;
	/*b.left = &d; b.right = &e;
	d.left = &g;*/
	s.maxPathSum(&a);
	return 0;
}