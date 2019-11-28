class Solution
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		int res = 0;
		unordered_map<int, int> m;
		vector<vector<int>> v;
		for (int i = 0; i < nums.size(); ++i)
		{
            if (m.find(nums[i]) != m.end()) continue;
			if (m.find(nums[i] - 1)==m.end() && m.find(nums[i] + 1)==m.end())
			{
				v.push_back({ nums[i],nums[i] });
				m[nums[i]] = v.size() - 1;
				if (1 > res) res = 1;
				continue;
			}
			if (m.find(nums[i] - 1)==m.end() && m.find(nums[i] + 1)!=m.end())
			{
				int t = m[nums[i] + 1];
				v[t][0] = nums[i];
				m[nums[i]] = t;
				if (v[t][1] - v[t][0] + 1 > res) res = v[t][1] - v[t][0] + 1;
				continue;
			}
			if (m.find(nums[i] - 1)!=m.end() && m.find(nums[i] + 1)==m.end())
			{
				int t = m[nums[i] - 1];
				v[t][1] = nums[i];
				m[nums[i]] = t;
				if (v[t][1] - v[t][0] + 1 > res) res = v[t][1] - v[t][0] + 1;
				continue;
			}
			if (m.find(nums[i] - 1)!=m.end() && m.find(nums[i] + 1)!=m.end())
			{
				int r = m[nums[i] + 1];  int l = m[nums[i] - 1];
				v[r][0] = v[l][0]; 
				m[nums[i]] = r;
				m[v[r][0]] = r;
				if (v[r][1] - v[r][0] + 1 > res) res = v[r][1] - v[r][0] + 1;
				continue;
			}
		}
		return res;
	}
};