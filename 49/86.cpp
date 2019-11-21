class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		map<string, int> m;
		vector<vector<string>> res;
		int size = strs.size();
		for (int i = 0; i < size; ++i)
		{
			string t = strs[i];
			sort(t.begin(), t.end());
			if (m.find(t) == m.end())
			{
				res.push_back({ strs[i] });
				m.insert({ t,res.size() - 1 });
			}
			else
			{
				res[m[t]].push_back(strs[i]);
			}
		}
		return res;
	}
};