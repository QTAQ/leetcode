#include<vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  typedef TreeNode n;
class Solution
{
public:
	void preorder(TreeNode *n, vector<TreeNode*> &v)
	{
		if (!n) return;
		v.push_back(n);
		preorder(n->left, v);
		preorder(n->right, v);
	}
	void flatten(TreeNode* root)
	{
		if (!root) return;
		vector<TreeNode*> v;
		preorder(root,v);
		TreeNode *x = v[0];
		for (int i = 1; i < v.size(); ++i)
		{
			x->left = NULL;
			x->right = v[i];
			x = v[i];
		}
		return;
	}
};
int main()
{
	Solution s;
	n a(1); n b(2); n c(3); n d(4); n e(5); n f(6);
	a.left = &b; b.left = &c; b.right = &d;
	a.right = &e; e.right = &f;
	s.flatten(&a);
	return 0;
}