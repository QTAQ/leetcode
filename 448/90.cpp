class Solution
{
public:
	vector<int> findDisappearedNumbers(vector<int>& nums)
	{
		vector<int> res;
		nums.push_back(0);
		for (int i = 0; i < nums.size(); ++i)
		{
			while (nums[i] != nums[nums[i]])
				swap(nums[i], nums[nums[i]]);
		}
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] != i) res.push_back(i);
		}
		return res;
	}
};