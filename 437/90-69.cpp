#include<unordered_set>
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
	 int res = 0;
	 void dfs(TreeNode *n, vector<int> &sumvec, int &sum, int idx)
	 {
		 if (!n) return;
		 int tmp = n->val;
		 if (tmp == sum) ++res;
		 for (int i = idx - 1; i >= 0; --i)
		 {
			 tmp += sumvec[i];
			 if (tmp == sum)
			 {
				 ++res;
				 break;
			 }
		 }
		 sumvec[idx] = n->val;
		 dfs(n->left, sumvec, sum, idx + 1);
		 dfs(n->right, sumvec, sum, idx + 1);
		 sumvec[idx] = 0;
	 }
	 int pathSum(TreeNode *root, int sum)
	 {
		 if (!root) return 0;
		 vector<int> sumvec(1000, 0);
		 dfs(root, sumvec, sum, 0);
		 return res;
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
	 string t = "10,5,3,3,n,n,-2,n,n,2,n,1,n,n,-3,n,11,n,n";
	 TreeNode *a = deserialize(t);
	 Solution s;
	 int q = s.pathSum(a,8);
	 return 0;
 }