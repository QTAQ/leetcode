class Solution
{
public:
	vector<vector<int>> res;
	void dfs(vector<int>& candidates, vector<int>& path, int target, int max)
	{
		if (target == 0)
		{
			res.push_back(path);
			return;
		}
		for (int i = candidates.size() - 1; i >= 0 && candidates[i] >= max; --i)
		{
			int t = candidates[i];
			path.push_back(t);
			if (target - t >= 0) dfs(candidates, path, target - t, t);
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<int> path;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, path, target, 0);
		return res;
	}
};