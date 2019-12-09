bool mycompare(pair<int, int> &a, pair<int, int> &b)
{
	return a.second > b.second;
}
class Solution
{
public:
	int partition(vector<pair<int, int>> &v, int lo, int hi)
	{
		int mi = rand() % (hi - lo + 1) + lo;
		swap(v[mi], v[lo]);
		auto p = v[lo];
		while (lo < hi)
		{
			while (lo < hi && v[hi].second <= p.second) --hi;
			v[lo] = v[hi];
			while (lo < hi && v[lo].second >= p.second) ++lo;
			v[hi] = v[lo];
		}
		v[lo] = p;
		return lo;
	}
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		unordered_map<int, int> c;
		vector<int> res;
		vector<pair<int, int>> v;
		for (int i = 0; i < nums.size(); ++i)
		{
			++c[nums[i]];
		}
		for (auto i : c)
		{
			v.push_back(i);
		}
		int l = 0;
		int r = v.size() - 1;
		int i = partition(v, 0, r);
		int t = k - 1;
		while (i != t)
		{
			if (i < t) l = i + 1;
			else r = i - 1;
			i = partition(v, l, r);
		}
		sort(v.begin(), v.begin() + i + 1, mycompare);
		for (int j = 0; j <= i; ++j)
		{
			res.push_back(v[j].first);
		}
		return res;
	}
};