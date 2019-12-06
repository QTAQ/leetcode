class Codec 
{
public:

	void preorder(TreeNode *n,string &s)
	{
		if (!n)
		{
			s += "n,";
			return;
		}
		s += to_string(n->val) + ',';
		preorder(n->left, s);
		preorder(n->right, s);
	}
	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		string res;
		preorder(root, res);
		res.pop_back();
		return res;
	}

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
		return construct(data,i);
	}
};