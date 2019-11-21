struct node
{
	int d;
	bool c;
	node() = default;
	node(int a, bool s) :d(a), c(s) {}
};
bool cmp(node a, node b)
{
	return a.d < b.d;
}
class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals)
	{
		int size = intervals.size();
		vector<vector<int>> res;
		node *vec = new node[2 * size];
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				vec[i * 2 + j].d = intervals[i][j];
				vec[i * 2 + j].c = ((j == 0) ? true : false);
			}
		}
		size *= 2;
		stable_sort(vec, vec + size, cmp);
		int stk = 0;
		int l;
		for (int i = 0; i < size; ++i)
		{
			if (vec[i].c)
			{
				if (stk == 0) l = vec[i].d;
				++stk;
			}
			else
			{
				--stk;
				if (stk == 0)
				{
					if (i + 1 < size && vec[i + 1].d == vec[i].d)
					{
						++stk;
						++i;
					}
					else res.push_back({ l,vec[i].d });
				}
			}
		}
		return res;
	}
};