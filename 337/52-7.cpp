#include<vector>
using namespace std;
#define max(a,b) (((a)<(b))?(b):(a))
struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
public:
	vector<int> dfs(TreeNode *n)
	{
		if (!n) return { 0,0 };
		vector<int> l = dfs(n->left);
		vector<int> r = dfs(n->right);
		int t1 = r[0] + l[0];
		int t0 = l[1] + r[1] + n->val;
		return { (t1>t0)?t1:t0, t1 };
	}
	int rob(TreeNode* root)
	{
		return dfs(root)[0];
	}
};
TreeNode *construct(string &data, int &i)
{
	if (i >= data.size() || data[i] == 'n')
	{
		i += 2;
		return nullptr;
	}
	string t;
	while (i < data.size() && data[i] != ',') t += data[i++];
	++i;
	TreeNode *n = new TreeNode(atoi(t.c_str()));
	n->left = construct(data, i);
	n->right = construct(data, i);
	return n;
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data)
{
	int i = 0;
	return construct(data, i);
}
int main()
{
	Solution s;
	string q = "4,2,1,n,n,3,n,n,n";
	TreeNode* a = deserialize(q);
	int w = s.rob(a);
	return 0;
}