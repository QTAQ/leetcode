class Solution
{
public:
    unordered_map<int,int> m;
	TreeNode* rebuild(vector<int>& preorder, vector<int>& inorder, vector<int>::iterator pl, vector<int>::iterator ph,
		vector<int>::iterator il, vector<int>::iterator ih)
	{
		if (pl == ph || ih == il) return nullptr;
		int mi = m[*pl];
		TreeNode *res = new TreeNode(inorder[mi]);
		int midx = mi - (il-inorder.begin());
		res->left = rebuild(preorder, inorder, pl + 1, pl + midx + 1, il, inorder.begin()+mi);
		res->right = rebuild(preorder, inorder, pl + midx + 1, ph, inorder.begin() + mi + 1, ih);
		return res;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
        for(int i=0;i<inorder.size();++i){
            m[inorder[i]] = i;
        }
		return rebuild(preorder, inorder, preorder.begin(), preorder.end(),
						inorder.begin(), inorder.end());
	}
};