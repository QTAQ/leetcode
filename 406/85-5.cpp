bool cmp(vector<int> &a, vector<int> & b)
{
	if (a[0] > b[0]) return true;
	if (a[0] == b[0] && a[1] < b[1]) return true;
	return false;
}
class Solution
{
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
	{
		vector<vector<int>> res;
		sort(people.begin(), people.end(), cmp);
		for (auto i : people)
		{
			res.insert(res.begin() + (i)[1], i);
		}
		return res;
	}
};