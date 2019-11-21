class Solution
{
public:
	bool *visited = nullptr;
	vector<vector<int>> res;
	void dfs(vector<int>& nums, vector<int>& path, const int &cnt, int &size)
	{
		if (cnt == 0)
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i < size; ++i)
		{
			if (!visited[i]) continue;
			path.push_back(nums[i]);
			visited[i] = false;
			dfs(nums, path, cnt - 1, size);
			path.pop_back();
			visited[i] = true;
		}
	}
	vector<vector<int>> permute(vector<int>& nums)
	{
		int size = nums.size();
		visited = new bool[size];
		for (int i = 0; i < size; ++i)
		{
			visited[i] = true;
		}
		vector<int> path;
		for (int i = 0; i < size; ++i)
		{
			path.push_back(nums[i]);
			visited[i] = false;
			dfs(nums, path, size - 1, size);
			path.pop_back();
			visited[i] = true;
		}
		return res;
	}
};