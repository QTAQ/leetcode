class Solution
{
public:
	vector<vector<int>> res = { {} };
	void dfs(vector<int>& nums, vector<int>& path, int &beg, const int &depth)
	{
		if (depth == 0)
		{
			res.push_back(path);
		}
		for (int i = beg + 1; i < nums.size(); ++i)
		{
			path.push_back(nums[i]);
			dfs(nums, path, i, depth - 1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<int> path;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int d = nums.size(); d >= 0; --d)
			{
				if (i + d <= nums.size())
				{
					path.push_back(nums[i]);
					dfs(nums, path, i, d);
					path.pop_back();
				}
			}
		}
		return res;
	}
};