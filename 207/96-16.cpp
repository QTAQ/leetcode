struct node
{
	int val=-1;
	int status = 0;
	vector<node*> nbh;
	node() = default;
	node(int x):val(x){}
};
class Solution
{
public:
	bool DFS(vector<node*> &n)
	{
		int s = n.size();
		int i = 0;
		do
		{
			if (n[i]->status == 0)
			{
				if (dfs(n[i])) ++i;
				else return false;
			}
			else ++i;
		} while (i!=s);
		return true;
	}
	bool dfs(node *n)
	{
		n->status = 1;
		for (int i = 0; i < n->nbh.size(); ++i)
		{
			switch (n->nbh[i]->status)
			{
			case 0:
				if (!dfs(n->nbh[i])) return false;
				break;
			case 1:
				return false;
			default:
				break;
			}
		}
		n->status = 2;
		return true;
	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		if (numCourses == 1) return true;
		vector<node*> n;
		for (int i = 0; i < numCourses; ++i) n.push_back(new node(i));
		for (int i = 0; i < prerequisites.size(); ++i)
		{
			n[prerequisites[i][1]]->nbh.push_back(n[prerequisites[i][0]]);
		}
		return DFS(n);
	}
};